#include <iostream>
#include <iomanip>
using namespace std;

int a[64][64], tile = 0;

void tromino(int r, int c, int n, int mr, int mc) {
    if (n == 2) {
        tile++;
        for (int i = r; i < r + 2; i++)
            for (int j = c; j < c + 2; j++)
                if (i != mr || j != mc)
                    a[i][j] = tile;
        return;
    }

    int h = n / 2;
    int cr = r + h - 1, cc = c + h - 1;

    bool TL = mr < r+h && mc < c+h;
    bool TR = mr < r+h && mc >= c+h;
    bool BL = mr >= r+h && mc < c+h;

    tile++;

    if (!TL) a[cr][cc] = tile;
    if (!TR) a[cr][cc+1] = tile;
    if (!BL) a[cr+1][cc] = tile;
    if (TL || TR || BL) a[cr+1][cc+1] = tile;

    tromino(r, c, h, TL ? mr : cr, TL ? mc : cc);
    tromino(r, c+h, h, TR ? mr : cr, TR ? mc : cc+1);
    tromino(r+h, c, h, BL ? mr : cr+1, BL ? mc : cc);
    tromino(r+h, c+h, h,
            (!TL && !TR && !BL) ? mr : cr+1,
            (!TL && !TR && !BL) ? mc : cc+1);
}

int main() {
    int n, r, c;
    cin >> n >> r >> c;

    r--; c--;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = 0;

    a[r][c] = -1;
    tromino(0, 0, n, r, c);

    cout << "\nTiled Grid:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(3) << (a[i][j] == -1 ? -1 : a[i][j]);
        cout << '\n';
    }

    cout << "\nNumber of tiles = " << tile << endl;
}
