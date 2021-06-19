/**
 * Mandelbrot in C
 * influenced from Rosetta Code
 */

int main(void) {
    // some initial data
    int axis_x = 25;  // x res
    int axis_y = 50;
    int iterations = 256;  // no of iterations to carry out
    // dimensional data
    double x_min = 0.275;
    double y_min = 0.005;
    double x_max = 0.300;
    double y_max = 0.010;
    // calculate diffs
    double xvar = (x_max - x_min) / axis_y;
    double yvar = (y_max - y_min) / axis_x;
    // temps 
    unsigned i, j, k;  // counters
    double temp_dx = 0.0;
    // executions
    for (i = 0; i < axis_x; i++) {
        for (j = 0; j < axis_y; j++) {

            double dx = 0.0;
            double dy = 0.0;
            
            double kx = x_min + j * xvar;
            double ky = y_min + i * yvar;
            
            for(k=0; (dx * dx + dy * dy < 4.0) && ( k < iterations ); k++) {
                temp_dx = (dx * dx) - (dy * dy) + kx;
                dy = 2.0 * dx * dy + ky;
                dx = temp_dx;
            }

            if(k == iterations) {
                k = 0;
            }
        }
    }
    
    return 0;
}
