import java.util.Scanner;
public class dsalab1{
  
  static void printarr(int a[]){
     int n= a.length;
        for(int i=0;i<n;i++){
            System.out.print(a[i]+"|");
        }System.out.println();
    }
    int sort(int arr[])
	{
		int n = arr.length;

		
		for (int gap = n/2; gap > 0; gap /= 2)
		{
			
			for (int i = gap; i < n; i += 1)
			{
				
				int temp = arr[i];

				int j;
				for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
					arr[j] = arr[j - gap];

				arr[j] = temp;
                printarr(arr);
		}
            	
        }
		return 0;
	}
    
    public static void main(String[] args) {
       
        int n;
       
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter no of Elements you want : ");
        n= sc.nextInt();
        int Arr[]= new int[n];
       if(n>10){
           System.out.println("Array  Limit Not in range.");
       }else
    {System.out.println("Enter the array elements:");
        for(int i= 0; i<n; i++){
           Arr[i]=sc.nextInt();
       }

        System.out.println("The Array is: ");
        printarr(Arr);
        dsalab1 ob =new dsalab1();
        ob.sort(Arr);
        System.out.println("The sorted Array is: ");
        printarr(Arr);
    }
    }
   
}