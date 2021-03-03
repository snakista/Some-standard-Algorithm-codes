#include <bits/stdc++.h>
using namespace std;
const double g = 9.81;
const double pi = 3.14159265;
double fun(double t, double i)
{
    return (2.5 - (1.25 * i));
}
void euler()
{
    double h = 0.05;
    double n = 2.2; // to find at
    double ynmo = 1;
    double xnmo = 2;
    double yn;
    for (double i = xnmo + h; i <= n; i += h)
    {
        double temp = fun(i - h, ynmo);
        yn = ynmo + h * temp;
        cout << "f(xnmo,ynmo) = " << temp << " ";
        cout << " yn at " << i << " is : " << yn << endl;
        ynmo = yn;
    }
}
void me()
{
    double h = 0.1;
    double n = 0.2;  // value to find
    double ynmo = 1; //initial cond
    double xnmo = 0; //initial cond
    double yn;       // do not initialize
    double ynm;
    for (double i = xnmo + h; i <= n; i += h)
    {
        double tmp1, tmp2;
        tmp1 = fun(i - h, ynmo);
        yn = ynmo + h * tmp1;
        tmp2 = fun(i, yn);
        cout << "f(xnmo,ynmo) = " << tmp1 << " "
             << "f(tn,yn) = " << tmp2 << " ";
        cout << "yn at (euler) " << i << " is : " << yn << endl;
        ynm = ynmo + (0.5 * h) * (tmp1 + tmp2);
        cout << "yn at (me) " << i << " is : " << ynm << endl;
        ynmo = ynm;
    }
}
void rk2()
{
    double h = 0.25;
    double n = 0.5;  // value to find
    double ynmo = 0; //initial cond
    double xnmo = 0; //initial cond
    double yn;       // do not initialize
    double k1, k2;
    for (double i = xnmo + h; i <= n; i += h)
    {
        k1 = fun(i - h, ynmo);
        k2 = fun(i, ynmo + k1 * h);
        yn = ynmo + (0.5 * h) * (k1 + k2);
        cout << "k1 = " << k1 << endl;
        cout << "k2 = " << k2 << endl;
        cout << "yn at (rk2) " << i << " is : " << yn << endl;
        ynmo = yn;
    }
}
void rk4()
{
    double h = 0.2;
    double n = 0.4;  // value to find
    double ynmo = 1; //initial cond
    double xnmo = 0; //initial cond
    double yn;       // do not initialize
    double k1, k2, k3, k4;
    for (double i = xnmo + h; i <= n; i += h)
    {
        k1 = fun(i - h, ynmo);
        k2 = fun(i - h + (0.5 * h), ynmo + (k1 * h * 0.5));
        k3 = fun(i - h + (0.5 * h), ynmo + (k2 * h * 0.5));
        k4 = fun(i, ynmo + k3 * h);
        yn = ynmo + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
        cout << "k1 = " << k1 << endl;
        cout << "k2 = " << k2 << endl;
        cout << "k3 = " << k3 << endl;
        cout << "k4 = " << k4 << endl;
        cout << "yn at (rk4) " << i << " is : " << yn << endl;
        ynmo = yn;
    }
}
//************numerical integration****************
double f(double x)
{
    // use exp(x) for e^x
    return (double)(exp((-1 * x * x) / 2));
}
void trap()
{
    int n;
    double a, b;
    cout << "Enter value of n: ";
    cin >> n;
    double y[n + 1];
    cout << "Enter a and b : ";
    cin >> a >> b;
    double h = ((b - a) / n);
    int k = 0;
    for (double i = a; i <= b; i += h)
    {
        y[k] = f(i);
        cout << "y at x = " << i << " is: " << y[k] << endl;
        k += 1;
    }
    double val = 0;
    val += y[0];
    val += y[n];
    for (int i = 1; i < n; i++)
    {
        val += (2 * y[i]);
    }
    val = (val * h) / 2;
    cout << val << endl;
}
void simp1()
{
    int n;
    double a, b;
    cout << "Enter value of n (muntiple of 2): ";
    cin >> n;
    double y[n + 1];
    cout << "Enter a and b : ";
    cin >> a >> b;
    double h = ((b - a) / n);
    int k = 0;
    for (double i = a; i <= b; i += h)
    {
        y[k] = f(i);
        cout << "y at x = " << i << " is: " << y[k] << endl;
        k += 1;
    }
    double val = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i == 0 || i == n)
            val += y[i];
        else if (i % 2 == 0)
            val += (2 * y[i]);
        else
            val += (4 * y[i]);
    }
    val = (val * h) / 3;
    cout << val << endl;
}
void simp2()
{
    int n;
    double a, b;
    cout << "Enter value of n (muntiple of 3): ";
    cin >> n;
    double y[n + 1];
    cout << "Enter a and b : ";
    cin >> a >> b;
    double h = ((b - a) / n);
    int k = 0;
    for (double i = a; i <= b; i += h)
    {
        y[k] = f(i);
        cout << "y at x = " << i << " is: " << y[k] << endl;
        k += 1;
    }
    double val = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i == 0 || i == n)
            val += y[i];
        else if (i % 3 == 0)
            val += (2 * y[i]);
        else
            val += (3 * y[i]);
    }
    val = (val * 3 * h) / 8;
    cout << val << endl;
}
//********************************Interpolation*************************
int fec(int x)
{
    int res = 1;
    for (int i = 1; i <= x; i++)
        res *= i;
    return res;
}
void fd()
{
    int n;
    double x, y, h;
    cout << "Enter no of datapoints: ";
    cin >> n;
    double Y[n][n];
    double X[n];
    cout << "Enter h: ";
    cin >> h;
    cout << "Enter datapoints (x,y): ";
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        X[i] = x;
        Y[i][0] = y;
    }
    int k = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < (n - k); j++)
        {
            Y[j][i] = Y[j + 1][i - 1] - Y[j][i - 1];
        }
        k++;
    }
    cout << "Enter target value: ";
    cin >> x;
    double ans = Y[0][0];
    double p = (x - X[0]) / h;
    double r = 1;
    for (int i = 1; i < n; i++)
    {
        r *= (p - i + 1);
        ans += (r * Y[0][i]) / (fec(i));
    }
    cout << ans << endl;
}
void bd()
{
    int n;
    double x, y, h;
    cout << "Enter no of datapoints: ";
    cin >> n;
    double Y[n][n];
    double X[n];
    cout << "Enter h: ";
    cin >> h;
    cout << "Enter datapoints (x,y): ";
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        X[i] = x;
        Y[i][0] = y;
    }
    int k = n;
    for (int i = 1; i < n; i++)
    {
        for (int j = n - 1; j > (n - k); j--)
        {
            Y[j][i] = Y[j][i - 1] - Y[j - 1][i - 1];
        }
        k--;
    }
    cout << "Enter target value: ";
    cin >> x;
    double ans = Y[n - 1][0];
    double p = (x - X[n - 1]) / h;
    double r = 1;
    for (int i = 1; i < n; i++)
    {
        r *= (p + i - 1);
        ans += (r * Y[n - 1][i]) / (fec(i));
    }
    cout << ans << endl;
}
void lng()
{
    int n;
    cout << "Enter no of datapoints: ";
    cin >> n;
    double Y[n];
    double X[n];
    cout << "Enter datapoints (x,y): ";
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        cin >> Y[i];
    }
    double x;
    cout << "Enter target value: ";
    cin >> x;
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        double num = 1, deno = 1;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            num *= (x - X[j]);
            deno *= (X[i] - X[j]);
        }
        ans += ((num * Y[i]) / deno);
    }
    cout << ans << endl;
}
void dd()
{
    int n;
    double x, y;
    cout << "Enter no of datapoints: ";
    cin >> n;
    double Y[n][n];
    double X[n];
    cout << "Enter datapoints (x,y): ";
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        X[i] = x;
        Y[i][0] = y;
    }
    int k = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < (n - i); j++)
        {
            Y[j][i] = (Y[j + 1][i - 1] - Y[j][i - 1]) / (X[j + k] - X[j]);
        }
        k++;
    }
    cout << "Enter target value: ";
    cin >> x;
    double ans = Y[0][0];
    double r = 1;
    for (int i = 1; i < n; i++)
    {
        r *= (x - X[i - 1]);
        ans += (r * Y[0][i]);
    }
    cout << ans << endl;
}
//************************Solution of equations********************
double fn(double x)
{
    return (x * x);
}
double fnd(double x) //derivative for newton rapson
{
    return 2 * x;
}
void bis()
{
    double a, b, prv = 0, x1;
    cout << "Enter a and b such that f(a)<0 and f(b)>0: ";
    cin >> a >> b;
    while (1)
    {
        x1 = (a + b) / 2;
        if (x1 == prv)
            break;
        else if (x1 > prv && (x1 - prv <= 0.00001)) //  change according to accuracy
            break;
        else if (x1 < prv && (prv - x1) <= 0.00001) // cnage acc to accuracy
            break;
        cout << "a = " << a << " b = " << b << endl;
        cout << "x1 = " << x1 << " and f(x1) = " << fn(x1) << endl;
        if (fn(x1) < 0)
        {
            a = x1;
        }
        else if (fn(x1) > 0)
        {
            b = x1;
        }
        else
            break;
        prv = x1;
    }
    cout << "Approximate root is: " << x1 << endl;
}
void rf()
{
    double x0, x1, prv = 0, x;
    cout << "Enter x0 and x1 such that f(x0)<0 and f(x1)>0: ";
    cin >> x0 >> x1;
    while (1)
    {
        x = (x0 * fn(x1) - x1 * fn(x0)) / (fn(x1) - fn(x0));
        cout << "x0 = " << x0 << " x1 = " << x1 << endl;
        cout << "x = " << x << " and f(x) = " << fn(x) << endl;
        if (x == prv)
            break;
        else if (x > prv && ((x - prv) <= 0.00001)) //  change according to accuracy
            break;
        else if (x < prv && ((prv - x) <= 0.00001)) // cnage acc to accuracy
            break;
        if (fn(x) < 0)
        {
            x0 = x;
        }
        else if (fn(x) > 0)
        {
            x1 = x;
        }
        else
            break;
        prv = x;
    }
    cout << "Approximate root is: " << x << endl;
}
void nr()
{
    double prv, x;
    cout << "Enter x0 close to root: ";
    cin >> prv;
    while (1)
    {
        x = (prv - (fn(prv) / fnd(prv)));
        cout << "x = " << x << endl;
        if (x == prv)
            break;
        else if (x > prv && (x - prv <= 0.00001)) //  change according to accuracy
            break;
        else if (x < prv && (prv - x) <= 0.00001) // cnage acc to accuracy
            break;
        prv = x;
    }
    cout << "Approximate root is: " << x << endl;
}
void sc()
{
    double prv, x0, x1, x;
    int k = 3;
    cout << "Enter x0 and x1 such that f(x0)<0 and f(x1)>0: ";
    cin >> x0 >> x1;
    while (1)
    {
        x = (x0 * fn(x1) - x1 * fn(x0)) / (fn(x1) - fn(x0));
        cout << "x" << k << " = " << x << endl;
        if (x == prv)
            break;
        else if (x > prv && (x - prv <= 0.00001)) //  change according to accuracy
            break;
        else if (x < prv && (prv - x) <= 0.00001) // cnage acc to accuracy
            break;
        prv = x;
        x0 = x1;
        x1 = x;
        k++;
    }
    cout << "Approximate root is: " << x << endl;
}
int main()
{
    int ch;
    cout << "1. Euler" << endl;
    cout << "2. ME" << endl;
    cout << "3. RK 2" << endl;
    cout << "4. RK 4" << endl;
    cout << "5. Trapezoidal" << endl;
    cout << "6. Simpson 1/3" << endl;
    cout << "7. Simpson 3/8" << endl;
    cout << "8. Forward difference" << endl;
    cout << "9. Backward diffrence" << endl;
    cout << "10. Divided Difference" << endl;
    cout << "11. Langrange" << endl;
    cout << "12. Bisection" << endl;
    cout << "13. Regula falsi" << endl;
    cout << "14. Newton rapson" << endl;
    cout << "15. Secant" << endl;
    cout << "Enter choice: ";
    cin >> ch;
    if (ch == 1)
        euler();
    else if (ch == 2)
        me();
    else if (ch == 3)
        rk2();
    else if (ch == 4)
        rk4();
    else if (ch == 5)
        trap();
    else if (ch == 6)
        simp1();
    else if (ch == 7)
        simp2();
    else if (ch == 8)
        fd();
    else if (ch == 9)
        bd();
    else if (ch == 10)
        dd();
    else if (ch == 11)
        lng();
    else if (ch == 12)
        bis();
    else if (ch == 13)
        rf();
    else if (ch == 14)
        nr();
    else if (ch == 15)
        sc();
}