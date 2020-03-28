/* 	Code done by Adithya Shankar (B44)	 */
// Banker's Algorithm 
#include <stdio.h> 
int main() 
{ 
    // P0, P1, P2, P3, P4 are the Process names 
  
    int a, b, i, j, k; 
    a = 5; // Number of processes 
    b = 3; // Number of resources 
    int all[5][3] = { { 0, 1, 0 }, // P0    // Allocation Matrix 
                        { 2, 0, 0 }, // P1 
                        { 3, 0, 2 }, // P2 
                        { 2, 1, 1 }, // P3 
                        { 0, 0, 2 } }; // P4 
  
    int max[5][3] = { { 7, 5, 3 }, // P0    // MAX Matrix 
                      { 3, 2, 2 }, // P1 
                      { 9, 0, 2 }, // P2 
                      { 2, 2, 2 }, // P3 
                      { 4, 3, 3 } }; // P4 
  
    int avail[3] = { 3, 3, 2 }; // Available Resources 
  
    int n[a], ans[a], ind = 0; 
    for (k = 0; k < a; k++) { 
        n[k] = 0; 
    } 
    int need[a][b]; 
    for (i = 0; i < a; i++) { 
        for (j = 0; j < b; j++) 
            need[i][j] = max[i][j] - all[i][j]; 
    } 
    int y = 0; 
    for (k = 0; k < 5; k++) { 
        for (i = 0; i < a; i++) { 
            if (n[i] == 0) { 
  
                int flag = 0; 
                for (j = 0; j < b; j++) { 
                    if (need[i][j] > avail[j]){ 
                        flag = 1; 
                         break; 
                    } 
                } 
  
                if (flag == 0) { 
                    ans[ind++] = i; 
                    for (y = 0; y < m; y++) 
                        avail[y] += all[i][y]; 
                    n[i] = 1; 
                } 
            } 
        } 
    } 
  
    printf("Following is the SAFE State or Swquence\n");
    printf("Sequence is : ") 
    for (i = 0; i < a - 1; i++) 
        printf(" P%d ->", ans[i]); 
    printf(" P%d", ans[a - 1]); 
  
    return (0); 
   
}