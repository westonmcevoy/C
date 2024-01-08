#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**********************************************************************
 * API
 *********************************************************************/

typedef struct _matrix matrix;

/* Creates a "rows by cols" matrix with all values 0.
 * Returns NULL if rows <=0 or cols <= 0 and otherwise
 * a pointer to the new matrix.
 */
matrix * newMatrix(int rows, int cols);

/* Copies a matrix.  Returns NULL if mtx is NULL.
 */
matrix * copyMatrix(matrix const * mtx);

/* Deletes a matrix.  Returns 0 if successful and -1
 * if mtx is NULL.
 */
void deleteMatrix(matrix * mtx);

/* Sets the (row, col) element of mtx to val.
 * Returns 0 if successful, -1 if mtx is NULL, and
 * -2 if row or col are outside of the dimensions of
 * mtx.
 */
int setElement(matrix * mtx, int row, int col,
               double val);

/* Sets the reference val to the value of the
 * (row,col) element of mtx.  Returns 0 if successful,
 * -1 if either mtx or val is NULL, and -2 if row or
 * col are outside of the dimensions of mtx.
 */
int getElement(matrix const * mtx, int row, int col,
               double * val);

/* Sets the reference n to the number of rows of mtx.
 * Returns 0 if successful and -1 if mtx or n is NULL.
 */
int nRows(matrix const * mtx, int * n);

/* Sets the reference n to the number of columns of mtx.
 * Returns 0 if successful and -1 if mtx or n is NULL.
 */
int nCols(matrix const * mtx, int * n);

/* Prints the matrix to stdout.  Returns 0 if successful
 * and -1 if mtx is NULL.
 */
int printMatrix(matrix const * mtx);

/* Writes the transpose of matrix in into matrix out.
 * Returns 0 if successful, -1 if either in or out is
 * NULL, and -2 if the dimensions of the matrices are
 * incompatible.
 */
int transpose(matrix const * in, matrix * out);

/* Writes the sum of matrices mtx1 and mtx2 into
 * matrix sum.  Returns 0 if successful, -1 if any
 * of the matrices are NULL, and -2 if the dimensions
 * of the matrices are incompatible.
 */
int sum(matrix const * mtx1, matrix const * mtx2,
        matrix * sum);

/* Writes the product of the matrices mtx1 and mtx2 into
 * matrix prod.  Returns 0 if successful, -1 if any
 * of the matrices are NULL, and -2 if the dimensions
 * of the matrices are incompatible.
 */
int product(matrix const * mtx1, matrix const * mtx2,
            matrix * prod);

/* Writes the dot product of vectors v1 and v2 into
 * reference prod.  Returns 0 if successful, -1 if any
 * of v1, v2, or prod are NULL, -2 if either matrix
 * is not a vector, and -3 if the vectors are of
 * incompatible dimensions. */
int dotProduct(matrix const * v1, matrix const * v2,
               double * prod);

/* Returns 1 if a matrix is square and 0 otherwise. */
int isSquare(matrix const * mtx);

/* Sets a square matrix to the identity.  Returns 0
 * if successful; returns -1 if m is null or the
 * matrix is not square.
 */
int identity(matrix * m);

/* Returns 1 if m is a diagonal matrix and 0
 * otherwise.
 */
int isDiagonal(matrix const * mtx);

/* Returns 1 if m is an upper-triangular
 * matrix and 0 otherwise.
 */
int isUpperTriangular(matrix const * mtx);

/* Constructs a diagonal matrix from a vector.
 * Returns 0 if successful; returns -1 if either
 * argument is null, if the matrix is not square,
 * or if matrix and vector have incompatible
 * dimensions.
 */
int diagonal(matrix const * v, matrix * mtx);

/* Return 1 if mtx is square and symmetric and 0
 * otherwise (including if mtx is null).
 */
int symmetric(matrix const * mtx);

/* Returns column col of mtx as a new vector. Returns NULL
 * if mtx is NULL or col is inconsistent with mtx's
 * dimensions.
 */
matrix * getColumn(matrix const * mtx, int col);

/* Returns row row of mtx as a row vector. Returns NULL
 * if mtx is NULL or row is inconsistent with mtx's
 * dimensions.
 */
matrix * getRow(matrix const * mtx, int row);

/* Sets each element of mtx to the product of that element
 * with s. Returns -1 if mtx is NULL and 0 otherwise.
 */
int scalarProduct(double s, matrix * mtx);

/**********************************************************************
 * Application
 *********************************************************************/

/* Basic test of the library. */
void testBasic(void);

/* Test the new functions. */
void testSymmetric(void);
void testGetColumnGetRow(void);
void testScalarProduct(void);

int main(void) {
  testBasic();
  testSymmetric();
  testGetColumnGetRow();
  testScalarProduct();
  return 0;
}

void testBasic(void) {
  matrix * A, * Ac, * B, * c, * d, * M, * ct, * mdp;
  double dp;
  int err;
  A = newMatrix(3, 3); assert(A);
  err = setElement(A, 1, 1, 1.0); assert(!err);
  err = setElement(A, 1, 2, .25); assert(!err);
  err = setElement(A, 1, 3, -.1); assert(!err);
  err = setElement(A, 2, 2, .4); assert(!err);
  err = setElement(A, 2, 3, .3); assert(!err);
  err = setElement(A, 3, 2, .1); assert(!err);
  err = setElement(A, 3, 3, -.3); assert(!err);
  printf("Matrix A:\n");
  err = printMatrix(A); assert(!err);

  Ac = copyMatrix(A); assert(Ac);
  printf("\nCopy of A:\n");
  err = printMatrix(Ac); assert(!err);

  B = newMatrix(3, 3); assert(B);
  err = setElement(B, 1, 1, .5); assert(!err);
  err = setElement(B, 2, 2, 2.0); assert(!err);
  err = setElement(B, 3, 3, 1.0); assert(!err);
  printf("\nMatrix B:\n");
  err = printMatrix(B); assert(!err);

  c = newMatrix(3, 1); assert(c);
  err = setElement(c, 1, 1, 1.0); assert(!err);
  err = setElement(c, 3, 1, 1.0); assert(!err);
  printf("\nVector c:\n");
  err = printMatrix(c); assert(!err);

  d = newMatrix(3, 1); assert(d);
  err = setElement(d, 2, 1, 1.0); assert(!err);
  err = setElement(d, 3, 1, 1.0); assert(!err);
  printf("\nVector d:\n");
  err = printMatrix(d); assert(!err);

  M = newMatrix(3, 3); assert(M);
  err = transpose(A, M); assert(!err);
  printf("\nA':\n");
  err = printMatrix(M); assert(!err);

  ct = newMatrix(1, 3); assert(ct);
  err = transpose(c, ct); assert(!err);
  printf("\nc':\n");
  err = printMatrix(ct); assert(!err);

  err = sum(A, B, M); assert(!err);
  printf("\nA + B:\n");
  err = printMatrix(M); assert(!err);

  err = product(A, B, M); assert(!err);
  printf("\nA * B:\n");
  err = printMatrix(M); assert(!err);

  mdp = newMatrix(1, 1); assert(mdp);
  err = product(ct, d, mdp); assert(!err);
  err = getElement(mdp, 1, 1, &dp); assert(!err);
  printf("\nDot product (1): %.2f\n", dp);

  err = dotProduct(c, d, &dp); assert(!err);
  printf("\nDot product (2): %.2f\n", dp);

  err = product(A, c, d); assert(!err);
  printf("\nA * c:\n");
  err = printMatrix(d); assert(!err);

  deleteMatrix(A);
  deleteMatrix(Ac);
  deleteMatrix(B);
  deleteMatrix(c);
  deleteMatrix(d);
  deleteMatrix(M);
  deleteMatrix(ct);
  deleteMatrix(mdp);
}

void testSymmetric(void) {
    matrix * o; //not symmetric case
    int err;
    o = newMatrix(3, 3); assert(o);
    err = setElement(o, 1, 1, 1.0); assert(!err);
    err = setElement(o, 1, 2, .25); assert(!err);
    err = setElement(o, 1, 3, -.1); assert(!err);
    err = setElement(o, 2, 1, .4); assert(!err);
    err = setElement(o, 2, 2, .4); assert(!err);
    err = setElement(o, 2, 3, .3); assert(!err);
    err = setElement(o, 3, 1, .1); assert(!err);
    err = setElement(o, 3, 2, .1); assert(!err);
    err = setElement(o, 3, 3, -.3); assert(!err);
    printf("Matrix o:\n");
    err = printMatrix(o); assert(!err);
    err = symmetric(o); assert(!err);
    
    matrix * t; //symmetric and square case
    t = newMatrix(3, 3); assert(t); 
    err = setElement(t, 1, 1, 1.0); assert(!err);
    err = setElement(t, 1, 2, .25); assert(!err);
    err = setElement(t, 1, 3, 2.0); assert(!err);
    err = setElement(t, 2, 1, .25); assert(!err);
    err = setElement(t, 2, 2, 1.0); assert(!err);
    err = setElement(t, 2, 3, .1); assert(!err);
    err = setElement(t, 3, 1, 2.0); assert(!err);
    err = setElement(t, 3, 2, .1); assert(!err);
    err = setElement(t, 3, 3, 1.0); assert(!err);
    printf("Matrix t:\n");
    err = printMatrix(t); assert(!err);
    err = symmetric(t); assert(err);
    
    matrix * n; //not square case
    n = newMatrix(3, 4); assert(n);
    err = setElement(n, 1, 1, 1.0); assert(!err);
    err = setElement(n, 1, 2, .25); assert(!err);
    err = setElement(n, 1, 3, 2.0); assert(!err);
    err = setElement(n, 2, 1, .25); assert(!err);
    err = setElement(n, 2, 2, 1.0); assert(!err);
    err = setElement(n, 2, 3, .1); assert(!err);
    err = setElement(n, 3, 1, 1.0); assert(!err);
    err = setElement(n, 3, 2, .1); assert(!err);
    err = setElement(n, 3, 3, 0); assert(!err);
    printf("Matrix n:\n");
    err = printMatrix(n); assert(!err);
    err = symmetric(n); assert(!err);
}

void testGetColumnGetRow(void) {
    matrix * C;
    int err;
    int n = 2; //gets second column
    C = newMatrix(3, 3); assert(C);
    err = setElement(C, 1, 1, 1.0); assert(!err);
    err = setElement(C, 1, 2, .25); assert(!err);
    err = setElement(C, 1, 3, 2.0); assert(!err);
    err = setElement(C, 2, 1, .25); assert(!err);
    err = setElement(C, 2, 2, 1.0); assert(!err);
    err = setElement(C, 2, 3, .1); assert(!err);
    err = setElement(C, 3, 1, 1.0); assert(!err);
    err = setElement(C, 3, 2, .1); assert(!err);
    err = setElement(C, 3, 3, 0); assert(!err);
    printf("Matrix C:\n");
    err = printMatrix(C); assert(!err);
    printf("Column %d of C is:\n", n);
    err = printMatrix(getColumn(C,n)); assert(!err);
    
    matrix * D;
    n = 2; //gets second row
    D = newMatrix(3, 3); assert(D);
    err = setElement(D, 1, 1, 3.0); assert(!err);
    err = setElement(D, 1, 2, .2); assert(!err);
    err = setElement(D, 1, 3, 2.0); assert(!err);
    err = setElement(D, 2, 1, .25); assert(!err);
    err = setElement(D, 2, 2, 1.9); assert(!err);
    err = setElement(D, 2, 3, .1); assert(!err);
    err = setElement(D, 3, 1, 1.8); assert(!err);
    err = setElement(D, 3, 2, .61); assert(!err);
    err = setElement(D, 3, 3, 1.0); assert(!err);
    printf("Matrix D:\n");
    err = printMatrix(D); assert(!err);
    printf("Row %d of D is:\n", n);
    err = printMatrix(getRow(D,n)); assert(!err);
}

void testScalarProduct(void) {
    matrix * V;
    int err;
    int n = 2; //multiplied by positive number
    V = newMatrix(3, 3); assert(V);
    err = setElement(V, 1, 1, 3.0); assert(!err);
    err = setElement(V, 1, 2, .2); assert(!err);
    err = setElement(V, 1, 3, 2.0); assert(!err);
    err = setElement(V, 2, 1, .25); assert(!err);
    err = setElement(V, 2, 2, 1.9); assert(!err);
    err = setElement(V, 2, 3, .1); assert(!err);
    err = setElement(V, 3, 1, 1.8); assert(!err);
    err = setElement(V, 3, 2, .61); assert(!err);
    err = setElement(V, 3, 3, 1.0); assert(!err);
    printf("Matrix V:\n");
    err = printMatrix(V); assert(!err);
    err = scalarProduct(n,V); assert(!err);
    printf("After multiplied by scalar %d:\n",n);
    printMatrix(V);
    
    n = -3; //multiplied by negative number
    V = newMatrix(3, 3); assert(V);
    err = setElement(V, 1, 1, 3.0); assert(!err);
    err = setElement(V, 1, 2, .2); assert(!err);
    err = setElement(V, 1, 3, 2.0); assert(!err);
    err = setElement(V, 2, 1, .25); assert(!err);
    err = setElement(V, 2, 2, 1.9); assert(!err);
    err = setElement(V, 2, 3, .1); assert(!err);
    err = setElement(V, 3, 1, 1.8); assert(!err);
    err = setElement(V, 3, 2, .61); assert(!err);
    err = setElement(V, 3, 3, 1.0); assert(!err);
    printf("Matrix V:\n");
    err = printMatrix(V); assert(!err);
    err = scalarProduct(n,V); assert(!err);
    printf("After multiplied by scalar %d:\n",n);
    printMatrix(V);
    
    n = 0; //multiplied by 0
    V = newMatrix(3, 3); assert(V);
    err = setElement(V, 1, 1, 3.0); assert(!err);
    err = setElement(V, 1, 2, .2); assert(!err);
    err = setElement(V, 1, 3, 2.0); assert(!err);
    err = setElement(V, 2, 1, .25); assert(!err);
    err = setElement(V, 2, 2, 1.9); assert(!err);
    err = setElement(V, 2, 3, .1); assert(!err);
    err = setElement(V, 3, 1, 1.8); assert(!err);
    err = setElement(V, 3, 2, .61); assert(!err);
    err = setElement(V, 3, 3, 1.0); assert(!err);
    printf("Matrix V:\n");
    err = printMatrix(V); assert(!err);
    err = scalarProduct(n,V); assert(!err);
    printf("After multiplied by scalar %d:\n",n);
    printMatrix(V);
}

/**********************************************************************
 * Library implementation
 *********************************************************************/

struct _matrix {
  int rows;
  int cols;
  double * data;
};

static double getE(matrix const * mtx, int row, int col) {
  return mtx->data[(col-1) * mtx->rows + row - 1];
}

static void setE(matrix * mtx, int row, int col, double val) {
  mtx->data[(col-1) * mtx->rows + row - 1] = val;
}

static int badArgs(matrix const * mtx, int row, int col) {
  if (!mtx || !mtx->data)
    return -1;
  if (row <= 0 || row > mtx->rows ||
      col <= 0 || col > mtx->cols)
    return -2;
  return 0;
}

matrix * newMatrix(int rows, int cols) {
  int i;
  matrix * m;
  if (rows <=0 || cols <= 0) return NULL;

  /* allocate a matrix structure */
  m = (matrix *) malloc(sizeof(matrix));
  if (!m) return NULL;

  /* set dimensions */
  m->rows = rows;
  m->cols = cols;

  /* allocate a double array of length rows * cols */
  m->data = (double *) malloc(rows*cols*sizeof(double));
  if (!m->data) {
    free(m);
    return NULL;
  }
  /* set all data to 0 */
  for (i = 0; i < rows*cols; i++)
    m->data[i] = 0.0;

  return m;
}

void deleteMatrix(matrix * mtx) {
  if (mtx) {
    /* free mtx's data */
    free(mtx->data);
    /* free mtx itself */
    free(mtx);
  }
}

matrix * copyMatrix(matrix const * mtx) {
  matrix * cp;
  if (!mtx) return NULL;

  /* create a new matrix to hold the copy */
  cp = newMatrix(mtx->rows, mtx->cols);
  if (!cp) return NULL;

  /* copy mtx's data to cp's data */
  memcpy(cp->data, mtx->data,
         mtx->rows * mtx->cols * sizeof(double));

  return cp;
}

int setElement(matrix * mtx, int row, int col,
               double val) {
  int err = badArgs(mtx, row, col);
  if (err) return err;
  setE(mtx, row, col, val);
  return 0;
}

int getElement(matrix const * mtx, int row, int col,
               double * val) {
  int err = badArgs(mtx, row, col);
  if (err) return err;
  if (!val) return -1;

  *val = getE(mtx, row, col);
  return 0;
}

int nRows(matrix const * mtx, int * n) {
  if (!mtx || !n) return -1;
  *n = mtx->rows;
  return 0;
}

int nCols(matrix const * mtx, int * n) {
  if (!mtx || !n) return -1;
  *n = mtx->cols;
  return 0;
}

int printMatrix(matrix const * mtx) {
  int row, col;

  if (!mtx) return -1;

  for (row = 1; row <= mtx->rows; row++) {
    for (col = 1; col <= mtx->cols; col++) {
      /* Print the floating point element with
       *  - either a - if negative of a space if positive
       *  - at least 3 spaces before the .
       *  - precision to the hundredths place */
      printf("% 6.2f ", getE(mtx, row, col));
    }
    /* separate rows by newlines */
    printf("\n");
  }
  return 0;
}

int transpose(matrix const * in, matrix * out) {
  int row, col;
  if (!in || !out)
    return -1;
  if (in->rows != out->cols || in->cols != out->rows)
    return -2;

  for (row = 1; row <= in->rows; row++)
    for (col = 1; col <= in->cols; col++)
      setE(out, col, row, getE(in, row, col));
  return 0;
}

int sum(matrix const * mtx1, matrix const * mtx2,
        matrix * sum) {
  int row, col;
  if (!mtx1 || !mtx2 || !sum) return -1;
  if (mtx1->rows != mtx2->rows ||
      mtx1->rows != sum->rows ||
      mtx1->cols != mtx2->cols ||
      mtx1->cols != sum->cols)
    return -2;

  for (col = 1; col <= mtx1->cols; col++)
    for (row = 1; row <= mtx1->rows; row++)
      setE(sum, row, col, getE(mtx1, row, col) + getE(mtx2, row, col));
  return 0;
}

int product(matrix const * mtx1, matrix const * mtx2,
            matrix * prod) {
  int row, col, k;
  if (!mtx1 || !mtx2 || !prod) return -1;
  if (mtx1->cols != mtx2->rows ||
      mtx1->rows != prod->rows ||
      mtx2->cols != prod->cols)
    return -2;

  for (col = 1; col <= mtx2->cols; col++)
    for (row = 1; row <= mtx1->rows; row++) {
      double val = 0.0;
      for (k = 1; k <= mtx1->cols; k++)
        val += getE(mtx1, row, k) * getE(mtx2, k, col);
      setE(prod, row, col, val);
    }
  return 0;
}

int dotProduct(matrix const * v1, matrix const * v2,
               double * prod) {
  int i;
  if (!v1 || !v2 || !prod) return -1;
  if (v1->cols != 1 || v2->cols != 1) return -2;
  if (v1->rows != v2->rows) return -3;

  *prod = 0;
  for (i = 1; i <= v1->rows; i++)
    *prod += getE(v1, i, 1) * getE(v2, i, 1);
  return 0;
}

int isSquare(matrix const * mtx) {
  return mtx && mtx->rows == mtx->cols;
}

int identity(matrix * m) {
  int row, col;
  if (!isSquare(m)) return -1;
  for (col = 1; col <= m->cols; col++)
    for (row = 1; row <= m->rows; row++)
      if (row == col)
        setE(m, row, col, 1.0);
      else
        setE(m, row, col, 0.0);
  return 0;
}

int isDiagonal(matrix const * mtx) {
  int row, col;
  if (!isSquare(mtx)) return 0;
  for (col = 1; col <= mtx->cols; col++)
    for (row = 1; row <= mtx->rows; row++)
      if (row != col && getE(mtx, row, col) != 0.0)
        return 0;
  return 1;
}

int isUpperTriangular(matrix const * mtx) {
  int row, col;
  if (!isSquare(mtx)) return 0;
  for (col = 1; col <= mtx->cols; col++)
    for (row = col+1; row <= mtx->rows; row++)
      if (getE(mtx, row, col) != 0.0)
        return 0;
  return 1;
}

int diagonal(matrix const * v, matrix * mtx) {
  int row, col;
  if (!v || !mtx || v->rows != mtx->rows ||
      mtx->rows != mtx->cols)
    return -1;
  for (col = 1; col <= mtx->cols; col++)
    for (row = 1; row <= mtx->rows; row++)
      if (row == col)
        setE(mtx, row, col, getE(v, row, 1));
      else
        setE(mtx, row, col, 0.0);
  return 0;
}

int symmetric(matrix const * mtx){
    int rows = mtx->rows;
    int cols = mtx->cols;
    if(!mtx){return 0;}
    if(rows != cols){return 0;}
    matrix * Tmtx = newMatrix(rows,cols);
    transpose(mtx,Tmtx);
    for(int i=0;i<(rows*cols);i++){
        if(mtx->data[i] != Tmtx->data[i]){return 0;}
    }
    return 1;
}

matrix * getColumn(matrix const * mtx, int col){
    int cols = mtx->cols;
    int rows = mtx->rows;
    if(!mtx){return NULL;}
    if(col > cols){return NULL;}
    matrix * R = newMatrix(rows,1);
    int strt = (col-1)*rows;
    int j = 0;
    for(int i = strt;i<strt+rows;i++){
        R->data[j] = mtx->data[i];
        j++;
    }
    return R;
}

matrix * getRow(matrix const * mtx, int row){
    int cols = mtx->cols;
    int rows = mtx->rows;
    if(!mtx){return NULL;}
    if(row > rows){return NULL;}
    matrix * R = newMatrix(1,cols);
    int strt = row-1;
    int j = 0;
    for(int i = strt;i<=strt+(cols-1)*(rows);i=i+rows){
        R->data[j] = mtx->data[i];
        j++;
    }
    return R;
}

int scalarProduct(double s, matrix* mtx){
    if(!mtx){return -1;}
    int rows = mtx->rows;
    int cols = mtx->cols;
    for(int i = 0;i<rows*cols-1;i++){
        mtx->data[i] = mtx->data[i]*s;
    }
    return 0;
}
