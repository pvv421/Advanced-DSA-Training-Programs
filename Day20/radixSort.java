class radixSort{
    static void countingSort(int arr[], int n, int exp)
{
    int output[] = new int[n];
    int count[] = new int[10];
    for(int i = 0; i<n; i++)
    {
        count[(arr[i]/exp)%10]++;
    }
    for(int i = 1; i<10; i++)
    {
        count[i] += count[i-1];
    }
    for(int i = n-1; i>=0; i--)
    {
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i = 0; i<n; i++)
    {
        arr[i] = output[i];
    }
}
static void radixSort(int arr[], int n)
{
    int max = arr[0];
    for( int i = 1; i<n; i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    for (int exp = 1; max/exp > 0; exp*=10)
    {
        countingSort(arr,n,exp);
    }
}
static void display(int a[], int n)
{
    for(int i = 0 ; i<n; i++)
        System.out.print(a[i]+" ");
    System.out.println();
}
public static void main(String [] args)
{
    int A[] = {525,131,755,112,567,976,111,100,653,322};
    int n = A.length;
    display(A,n);
    radixSort(A,n);
    display(A,n);
}
}