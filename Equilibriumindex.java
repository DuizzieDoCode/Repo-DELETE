//////////////////////////////////////Time complexity: O(n^2)///////////////////////////////////////////////
// public class Equilibriumindex {
//     public static void main(String[] args) {
//         int arr[]={-7, 1, 5, 1, -4, 3, -1};
//         int n=arr.length;
//         for(int i=0;i<=n-1;i++){
//             int leftsum=0;
//             for(int j=0;j<=i-1;j++){
//                 leftsum +=arr[j];
//             }
//             int rightsum=0;
//             for(int j=i+1;j<=n-1;j++){
//                 rightsum +=arr[j];
//             }
//             if(leftsum==rightsum){
//                 System.out.println("sds  "+i);
//             }
//         }
//     }
// }


//////////////////////////////////////Time complexity: O(n)///////////////////////////////////////////////
public class Equilibriumindex{
    public static void main(String[] args) {
        int sum=0,leftsum=0;
        int arr[]={-7, 2, 5, 2, -4, 3, 1};
        int n=arr.length;
        for(int i=0;i<n;i++){
            sum +=arr[i];
        }
        System.out.println("Sum is : "+sum);
        for(int i=0;i<n;i++){
            sum =sum-arr[i];
            if(sum==leftsum){
                System.out.println(i);
            }
            leftsum=leftsum+arr[i];
        }
    }
}