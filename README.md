# Project

## Behold the monstrosity:

```cpp
	if ((y > 1950 && y < 2100) &&
		(	// warunek na lata przestepne... <3
		(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d > 0 && d < 32)
			||
			(m == 3 || m == 6 || m == 9 || m == 11) && (d > 0 && d < 31)
			||
			(m == 2 && d > 0 && d < 29)
			||
			(m == 2 && y % 4 == 0 && y % 10 != 0 && (d > 0 && d < 30))
			)
		&& (h > -1 && h < 24) && (min > -1 && min < 60))
	{
		dep_time.year = y;
		dep_time.mon = m;
		dep_time.day = d;
		dep_time.hour = h;
		this->dep_time.min = min;
	}

	else
	{
		cout << "Wrong data given. Default values have been set." << endl;
		dep_time.year = 0;
		dep_time.mon = 0;
		dep_time.day = 0;
		dep_time.hour = 0;
		this->dep_time.min = 0;
}
``` 