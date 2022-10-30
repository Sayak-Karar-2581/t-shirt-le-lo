import java.util.Scanner;
public class FirstPattern
{
  public static void main(String[] args)
  {
    Scanner scanner = new Scanner(System.in);
    System.out.println("Enter number of rows to print--> ");
    int rows = scanner.nextInt();
    System.out.println("\nThe star pattern is :: ");
    for (int i = 1; i <= rows; i++)
    {
       for (int j = 1; j <= i; j++)
       {
         System.out.print("*");
       }
       System.out.println();
    }
  }
}
