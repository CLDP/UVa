#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN = 51;
const double INF = 1e15;
const double EPS = 1e-7;
const double SHIFT = EPS * 100;

const int OPTIMAL = -1;
const int UNBOUNDED = -2;
const int FEASIBLE = -3;
const int INFEASIBLE = -4;
const int PIVOT_OK = 1;

int basic[MAXN], row[MAXN], col[MAXN];
double C0[MAXN];

int dcmp(double x) {
    if (x > EPS) return 1;
    if (x < -EPS) return -1;
    return 0;
}

int Pivot(int N, int M, double *C, double A[MAXN][MAXN], double *R, int &i, int &j) {
    int k = -1;
    for (j = 0; j <= N; ++j)
     if (!basic[j] && dcmp(C[j]) > 0)
      if (k < 0 || dcmp(C[j] - C[k]) > 0) k = j;
    j = k;
    if (k < 0) return OPTIMAL;
    double mins = INF;
    k = -1;
    for (i = 1; i <= M; ++i)
     if (dcmp(A[i][j]) > 0)
      if (dcmp(R[i] / A[i][j] - mins) < 0) {
          mins = R[i] / A[i][j];
          k = i;
      }
    i = k;
    if (k < 0) return UNBOUNDED;
    return PIVOT_OK;
}

int PhaseII(int N, int M, double *C, double A[MAXN][MAXN], double *R, double &ans, int PivotIndex) {
    int i, j, k;
    while (k = Pivot(N, M, C, A, R, i, j), k == PIVOT_OK || PivotIndex) {
        if (PivotIndex) {
            j = 0;
            i = PivotIndex;
            PivotIndex = 0;
        }
        basic[row[i]] = 0;
        col[row[i]] = 0;
        basic[j] = 1;
        col[j] = i;
        row[i] = j;
        double temp = A[i][j];
        for (k = 0; k <= N; ++k) A[i][k] /= temp;
        R[i] /= temp;
        for (k = 1; k <= M; ++k) 
         if (k != i && dcmp(A[k][j])) {
             temp = -A[k][j];
             for (int l = 0; l <= N; ++l) A[k][l] += temp * A[i][l];
             R[k] += temp * R[i];
         }
        temp = -C[j];
        for (int l = 0; l <= N; ++l) C[l] += A[i][l] * temp;
        ans -= temp * R[i];
    }
    return k;
}

int PhaseI(int N, int M, double *C, double A[MAXN][MAXN], double *R, double &ans) {
    int k = -1;
    double minr = 0;
    for (int i = 1; i <= M; ++i) 
     if (dcmp(R[i] - minr) < 0) {
         minr = R[i];
         k = i;
     }
    if (k < 0) return FEASIBLE;
    for (int i = 1; i <= M; ++i) A[i][0] = -1;
    for (int j = 1; j <= N; ++j) C0[j] = 0;
    C0[0] = -1;
    double ans0 = 0;
    PhaseII(N, M, C0, A, R, ans0, k);
    if (dcmp(ans0) < 0) return INFEASIBLE;
    for (int i = 1; i <= M; ++i) A[i][0] = 0;
    for (int j = 1; j <= N; ++j) 
     if (dcmp(C[j]) && basic[j]) {
         double temp = C[j];
         ans += R[col[j]] * temp;
         for (int i = 0; i <= N; ++i) C[i] -= temp * A[col[j]][i];
     }
    return FEASIBLE;
}

int simplex(int N, int M, double *C, double A[MAXN][MAXN], double *R, double &ans, double *X) {  
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(basic, 0, sizeof(basic));
    memset(C0, 0, sizeof(C0));

    for (int i = 1; i <= M; ++i) {
        for (int j = N + 1; j <= N + M; ++j) A[i][j] = 0;
        A[i][N + i] = 1;
        A[i][0] = 0;
        row[i] = N + i;
        col[N + i] = i;
    }
    int k = PhaseI(N + M, M, C, A, R, ans);
    if (k == INFEASIBLE) return k;
    k = PhaseII(N + M, M, C, A, R, ans, 0);
    for (int j = 0; j <= N + M; ++j) X[j] = 0;
    for (int i = 1; i <= M; ++i) X[row[i]] = R[i];
    return k;
}

double ans, C[MAXN], A[MAXN][MAXN], R[MAXN], X[MAXN];

int main() {
    int N, M;
    while (cin >> N >> M) {
        memset(C, 0, sizeof(C));
        memset(A, 0, sizeof(A));
        memset(R, 0, sizeof(R));
        memset(X, 0, sizeof(X));
        for (int j = 1; j <= N; ++j) {
            cin >> C[j];
            C[j] *= M;
        }
        C[0] = 0;
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) cin >> A[i][j];
            cin >> R[i];
        }
        ans = 0;
        simplex(N, M, C, A, R, ans, X);
        cout << "Nasa can spend " << ceil(ans) << " taka." << endl;
    }
    return 0;
}
