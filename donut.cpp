#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
    float A = 0, B = 0; // Rotation angles
    float i, j; // Loop variables
    char b[1760]; // ASCII buffer for rendering
    float z[1760]; // Depth buffer for occlusion handling
    
    printf("\x1b[2J"); // Clear the screen
    
    for (;;) { // Infinite loop for continuous animation
        memset(b, 32, 1760);  // Fill buffer with spaces
        memset(z, 0, sizeof(z));   // Reset depth buffer
        
        for (j = 0; j < 6.28; j += 0.05) { // Loop over vertical angle
            for (i = 0; i < 6.28; i += 0.01) { // Loop over horizontal angle
                float c = sin(i); // Compute sine of i
                float d = cos(j); // Compute cosine of j
                float e = sin(A); // Compute sine of A (rotation)
                float f = sin(j); // Compute sine of j
                float g = cos(A); // Compute cosine of A (rotation)
                float h = d + 2; // Shifted depth factor
                float D = 1 / (c * h * e + f * g + 5); // Perspective transformation factor
                float l = cos(i); // Compute cosine of i
                float m = cos(B); // Compute cosine of B (rotation)
                float n = sin(B); // Compute sine of B (rotation)
                float t = c * h * g - f * e; // Transformed depth value
                
                int x = 40 + 30 * D * (l * h * m - t * n); // Compute screen X coordinate
                int y = 12 + 15 * D * (l * h * n + t * m); // Compute screen Y coordinate
                int o = x + 80 * y; // Compute buffer index
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n); // Compute brightness index
                
                if (y > 0 && y < 22 && x > 0 && x < 80 && D > z[o]) { // Check if pixel is within bounds and closer than previous
                    z[o] = D; // Update depth buffer
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0]; // Set ASCII character based on brightness
                }
            }
        }
        
        printf("\x1b[H"); // Move cursor to home position
        for (int k = 0; k < 1760; k++) { // Print the ASCII buffer
            putchar(k % 80 ? b[k] : 10); // Print character or newline
        }
        
        A += 0.08; // Increase increment for faster rotation
        B += 0.04; // Increase increment for faster rotation
    }
    
    return 0; // Program never reaches this point
}
