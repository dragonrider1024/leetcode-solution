class Solution {
public:
    int search(int A[], int n, int target) {
        return isearch(A,0,n-1,target);
    }
    
    int isearch(int A[], int i, int j, int target) {
        int m;
        if(i==j+1) return -1;
        m=(i+j)/2;
        if(A[m]>A[j]) {
            if(target==A[m]) return m;
            else if(target>A[m]) return isearch(A,m+1,j,target);
            else {
                if(target<=A[j]) return isearch(A,m+1,j,target);
                else return isearch(A,i,m-1,target);
            }
        }
        else if(A[m]<A[j]) {
            if(target==A[m]) return m;
            else if(target>A[m]) {
                if(target>A[j]) return isearch(A,i,m-1,target);
                else return isearch(A,m+1,j,target);
            }
            else return isearch(A,i,m-1,target);
        }
        else {
            if(target==A[m]) return m;
            else if(target>A[m]) return isearch(A,i,m-1,target);
            else return isearch(A,m+1,j,target);
        }
    }
};
