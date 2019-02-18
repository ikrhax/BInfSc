import java.util.Calendar;

public class Date 
{

	
	protected int day;
	protected int month;
	protected int year;
	
	protected String stringmonth = new String();
	protected String nameofday = new String();
	protected String smonth = new String();
	protected String lmonth = new String();
	
	protected String[] shortmonths = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	protected String[] longmonths = {"January","February","March","April","May","June","July","August","September","October","November","December"};
	protected String[] daynames = {"Sunday", "Monday", "Tuesday", "Wedensday", "Thursday", "Friday", "Saturday"};
	protected int[] monthdays = {31,28,31,30,31,30,31,31,30,31,30,31};
	
	
	/*
	 Constructors.  Because Java is a garbage collected language you cannot predict when (or even if) an object will be destroyed. 
	 Hence there is no direct equivalent of a destructor. 
	*/
	
	Date ()
	{
		 day = 1;
		 month = 0;
		 year = 1;
		
		 validateintmonth();
		 validateday();
		 validateyear();
		 domonthstuff();
	}
	
	Date (int y, String m, int d)
	{
		 day = d;
		 stringmonth = m;
		 year = y;
		 
		 validatestringmonthmaster();
		 validateday();
		 validateyear();
		 domonthstuff();
	}
	
	Date (int y, int m, int d)
	{
		/*
		 This is the constructor for Date if Month given as an Int. It sets Day, Month, and Year values and calls the required functions to prepare the Data. 
		*/
		
		 day = d;
		 month = m-1;
		 year = y;
		 
		 validateintmonth();
		 validateday();
		 validateyear();
		 domonthstuff();
	}
	
	
	/*
	 Interface Member Functions
	*/
	public void print()
	{
		/*
		 Irrelevant - will be overwritten by the print functions of the derived anyway. 
		*/
	}
	
	
	public void validateintmonth()
	{
		/*
		 This Function validates the month inputed as an int. It also produces both the short and long name version of the month.   
		*/
		
		if ((month<0)||(month>=12))
		{
		   System.out.println(month+" "+" is invalid! Month has been set to January.");
		   month = 1;
		}
		
	};
	
	public void validatestringmonthmaster()
	{
		int valid = 0;
		/*
		 This Function validates the month inputed as an string. In order to do this it sanitizes the input and checks it. 
		 It also produces both the short and long name version of the month.   
		*/

		/*
		 This cleans the input. It reduces the input to lower case, and then re-capitalizes the first letter in the string. 
		*/	
		
		char[] temp = stringmonth.toCharArray();
		int sz = temp.length;
		
		for (int i = 0; i < sz; i++)
		{
			temp[i] = Character.toLowerCase(temp[i]);
		}
		temp[0] = Character.toUpperCase(temp[0]);
		
		String temp2 = new String();
		
		for (Character c : temp)
		{
			temp2 += c.toString();
		}
		stringmonth = temp2;
		
		System.out.println(stringmonth);
		
		
		valid = validateshort();
		valid = validatelong();
		
		if (valid==0)
		{
			System.out.println(stringmonth+" "+" is invalid! Month has been set to January.");
			month = 0;
		}
		
	};
	
	public int validateshort ()
	{
		int valid = 0;
		for (int i = 0; i < 12; i++)
		{
			if (stringmonth == shortmonths[i])
			{
				valid = 1;
				month = i;
				smonth = shortmonths[month];
			}	
		}
		return valid;
	};
	
	public int validatelong()
	{
		int valid = 0;
		for (int i = 0; i < 12; i++)
		{
			if (stringmonth == longmonths[i])
			{
				valid = 1;
				month = i;
				lmonth = longmonths[month];
			}	
		}
		return valid;
	};

	
	
	public void validateday() 
	{
		/*
		 This Function validates the Day that is provided. It simply checks that it is within acceptable boundaries. 
		*/
		
	    if((day < 0)||(day > monthdays[month]))
		{
		   System.out.println(day+" "+" is invalid! Day has been set to 1.");
		   day = 1;
		}
	};
	
	public void validateyear()
	{
		if (year<0)
		{
			year = 1;
		}
		
		if ((year % 4 == 0 && year % 100 != 0) || ( year % 400 == 0))
		{
			monthdays[1]=29;
		}
	};
	
	
	
	public int calculatedayofweek(int d, int m, int y)
	{
		Calendar cal = Calendar.getInstance();
		cal.set(y, m, d);
		int day = cal.get(Calendar.DAY_OF_WEEK);
		return day;
	}

	
	
	
	public void domonthstuff()
	{
		/*
		 This Function uses the result of the above function to furnish the date class with the actual name of the day. 
		*/
		int temp = calculatedayofweek(day, month+1, year);
		nameofday = daynames[temp-1];
		smonth = shortmonths[month];
		lmonth = longmonths[month];	
		
	};

	
	/*
	 List of Protected Data Variables for Date Class	  
	*/

}
