#include <iostream>

using namespace std;
void compete_solution();
int main()
{
    compete_solution();
}
void compete_solution()
{
    int a, b, c, d, e, f;
    int a1, b1, c1, d1, e1, f1;
    cin >> a >> b >> c >> d >> e >> f;
    cin >> a1 >> b1 >> c1 >> d1 >> e1 >> f1;
    int x1 = d - a1, y1 = e - b1, z1 = f - c1;
    if (x1 > 0 && y1 > 0 && z1 > 0)
    {
        x1 = d1 - a, y1 = e1 - b, z1 = f1 - c;
        if (x1 > 0 && y1 > 0 && z1 > 0)
        {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}