using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication4
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] num = new int[100];
            int min = 0;
            int max = 0;
            int sum = 0;
            int i = 0;
            int j = 0;
            double average = 0;

            Console.WriteLine("Hello, please enter your numebrs below. Enter a negative value to stop: \n");
            while (num[j] >= 0)
            {
                num[i] = int.Parse(Console.ReadLine());
                min = num[i];

                if (num[i] > max)
                {
                    max = num[i];
                }
                if (num[i] > 0)
                {
                    if (num[i] < min)
                    {
                        min = num[i];
                    }
                }
                if (num[i] > 0)
                {
                    sum = sum + num[i];
                }
                i++;
                j = i - 1;
            } 
            average = sum / j;
            j = 0;
            Console.Write("\n");
            Console.Write("\n");
            Console.Write("Total number of values entered:   ");
            Console.Write(i-1);
            Console.Write("\n");
            Console.Write("Sum of values:                    ");
            Console.Write(sum);
            Console.Write("\n");
            Console.Write("Average of values:                ");
            Console.Write(average);
            Console.Write("\n");
            Console.Write("Minimum Value:                    ");
            Console.Write(min);
            Console.Write("\n");
            Console.Write("Maximum Value:                    ");
            Console.Write(max);
            Console.Write("\n");
            Console.Write("Values entered:                   ");
            Console.Write("\n");
            while (j != (i-1))
            {
                Console.Write(num[j]);
                Console.Write(" ");
                j++;
            }
            Console.Write("\n");
            Console.ReadKey();
        } 
    }
}
