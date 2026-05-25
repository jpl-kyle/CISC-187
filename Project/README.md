## 1.
```cpp
struct Player {
    std::string first_name;
    std::string last_name;
    std::string team;
};

std::vector<Player> sportPlayers(const std::vector<Player>&basketball, const std::vector<Player>&football) 
{
    std::vector<Player> dual_players;
    std::unordered_map<std::string, Player> basketball_roster;

    for (const auto&player : basketball)
    {
        std::string fullName = player.first_name + " " + player.last_name;
        basketball_roster[fullName] = player;
    }

    for (const auto&player : football)
    {
        std::string fullName = player.first_name + " " + player.last_name;
        
        if (basketball_roster.find(fullName) != basketball_roster.end()){
            dual_players.push_back(player);
        }
    }
    return dual_players;
}
```

## 2.
```cpp
int missingNumber(std::vector<int> array)
{
    int terms = array.size();
    int realSum = (terms * (terms+1))/2; // sum equation
    int givenSum = 0;

    for (int i=0; i<=array.size()-1; ++i)  
    {
        givenSum+=array[i];
    }

    if (givenSum==realSum) {
        return 0;
    }
    else
    {
        return realSum-givenSum; 
    }
}
```

## 3.
```cpp
int buySell(std::vector<int> array) 
{
    int minPrice = array[0];
    int minIndex = 0;

    int maxProfit = 0;
    int buy = 0;
    int sell = 0;

    for (int i=0; i<array.size(); ++i) { 
        if (array[i] < minPrice)
        {
            minPrice = array[i];
            minIndex = i;
        }

        int tempSell = array[i]-minPrice;

        if (tempSell > maxProfit) {
            maxProfit = tempSell;
            buy = minIndex;
            sell = i;
        }
    }

    std::cout << "Purchase at $" << array[buy] << ", sell at $" << array[sell] << " for $" << maxProfit << "." << endl;
    return 0;
}
```

## 4.
```cpp
int product(std::vector<int> array)
{
    int max1=array[0];
    int max2=array[1];
    if (max2 > max1) 
    {
        swap(max1,max2);
    }

    int min1=array[0];
    int min2=array[1];
    if (min2<min1)
    {
        swap(min1,min2);
    }

    for (int i=2; i<array.size(); ++i)
    {
        int element = array[i];

        if (element < min1) //find the 1st minimum
        {
            min2=min1;
            min1=element;
        }
        else if (element < min2) //find the 2nd minimum
        {
            min2=element;
        }
        
        if (element > max1) //find the first minimum
        {
            max2=max1;
            max1=element;
        }
        else if (element > max2) //find the second minimum
        {
            max2=element;
        }

        int posProduct = max1*max2;
        int negProduct = min1*min2;

        if (posProduct > negProduct)
        {
            return posProduct;
        }
        else
        {
            return negProduct;
        }
    }
    return 0;
}
```

## 5.
```cpp
double temperSort(std::vector<double>& array) //using counting sort
{
    double min = array[0]; 
    double max = array[0]; 
    for (int i = 1; i < array.size(); ++i) {
        if (array[i] < min) 
        {
            min = array[i]; //97.1
        }
        if (array[i] > max) 
        {
        max = array[i]; //99.0
        }
    }

    int convertedMin = std::round(min * 10.0); //971
    int convertedMax = std::round(max * 10.0); //990
    int range = convertedMax - convertedMin + 1; //990 - 971 + 1

    vector<int> tempArray(range, 0);
    for (double elem : array) 
    {
        int convertedValue = std::round(elem * 10);
        tempArray[convertedValue-convertedMin]++;
    }
    
    int index = 0;
    for (int i = 0; i < range; ++i) {
        while (tempArray[i] > 0) {
            array[index++] = (i + convertedMin) / 10.0;
            tempArray[i]--;
        }
    }
    return 0;
}
```

## 6.
```cpp
int straights(std::vector<int> array)
{
    int maxCount = 0;
    std::unordered_map<int, int> map;

    for (int element : array) { 

        int left = (map.find(element-1) != map.end() ? map[element-1] : 0); // assigns the amount of sequenced numbers left of the element if it exists, or 0
        int right =(map.find(element+1) != map.end() ? map[element+1] : 0); // assigns the amount of sequenced numbers right of the element if it exists, or 0
    
        int currentCount = left + right + 1; // adds the lengths of left + middle + right
        map[element] = currentCount; //inserts the current length of the element
        map[element - left] = currentCount;
        map[element + right] = currentCount;

        if (currentCount > maxCount)
        {
            maxCount = currentCount; //assign a new maxCount with a new longest sequence.
        }
    }
    
    return maxCount;
}
```
