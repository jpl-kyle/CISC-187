# Experimental Analysis
In the experimental analysis, I noticed that the sequential keys clustered together in adjacent buckets, even with random indexes. However, trailing sequential keys will scatter the information across distant buckets unless the word that the trailing numbers contain is the same throughout, in which case it will cluster in adjacent buckets. I did notice that in some cases, if there is a collision between a random string and a sequential key, the sequential key that collides with it is placed at the trailing end of the bucket.

# The Code
```cpp
#include <vector>
#include <list>
#include <string>
#include <iostream>
using namespace std;

class HashTable {
private:
    vector<list<pair<string, int>>> table; // a vector of lists with pair string + int
    int currentSize;
    int capacity;
    int collisionCount;

    int hashFunction(const string& key) const;
    void rehash();

public:
    HashTable() {
        int size = 11;
        capacity = size;
        currentSize = 0;
        collisionCount = 0;
        table.resize(capacity);
    }

    void insert(const string& key, int value);
    bool remove(const string& key);
    int search(const string& key) const;
    double loadFactor() const;
    int size() const;
    bool isEmpty() const;
    void printTable() const;
};

int main()
{
    HashTable table;

    /* testing
    table.insert("Stimpy", 745);
    table.insert("Dream", 3421);
    table.insert("Technoblade", 7210);
    table.insert("Grian", 4589);
    table.insert("Stampy", 5122);
    table.insert("Skeppy", 6109);
    table.insert("Stampy", 5122);
    table.insert("Philza", 5567);
    table.insert("EthosLab", 2109);
    table.insert("FitMC", 9234);
    table.insert("AntVenom", 1567);
    table.insert("SethBling", 7345);
    table.insert("TapL", 6754);
    table.insert("Fruitberries", 9123);
    table.insert("Illumina", 5432);
    table.insert("SpeedSilver", 2345);
    table.insert("Purpled", 7654);
    table.insert("Sneegsnag", 6541);
    table.insert("JackManifoldTV", 9876);
    table.insert("Nihachu", 5432);
    table.insert("Eret", 2109);
    table.insert("Fundy", 7345);
    table.insert("F1NN5TER", 3124);
    table.insert("Spifey", 6754);
    table.insert("Blushi", 9123);
    table.insert("FireBreathMan", 5432);
    table.insert("SB737", 7654);
    table.insert("DanTDM", 4321);
    table.insert("Wisp", 8912);
    table.insert("Puru", 1234);
    table.insert("5up", 6541);
    table.insert("BajanCanadian", 6789);
    table.insert("PrestonPlayz", 9345);
    table.insert("Krinios", 2567);
    table.insert("Krtzyy", 7891);
    table.insert("Michaelmcchill", 4123);
    table.insert("DeathStreeks", 8452);
    table.insert("Refraction", 7214);
    table.insert("ThirtyVirus", 5632);
    table.insert("Akinsoft", 4125);
    table.insert("Swavy", 8921);
    table.insert("HellCastle", 6734);
    table.insert("FurryEBoy", 3412);
    table.insert("MenacingBanana", 9021);
    table.insert("Sadan", 3456);
    table.insert("Thorn", 7891);
    table.insert("Livid", 4123);
    table.insert("Bonzo", 6542);
    table.insert("Scarf", 9012);
    table.insert("Maxor", 5674);
    table.insert("Storm", 1890);
    table.insert("Goldor", 7342);
    table.insert("Hausemaster", 9999);
    table.insert("TheCampingRusher", 7432);
    table.insert("iTristan", 9120);
    table.insert("Sato86", 6543);
    table.insert("Offtopia", 2109);
    table.insert("BarrenDome", 8876);
    table.insert("SalC1", 4321);
    table.insert("Nocom", 8765);
    table.insert("Bread_Stick", 3456);
    table.insert("Cyber_D0wn", 7891);
    table.insert("Etika", 4123);
    table.insert("Giggles", 6542);
    table.insert("Krool", 9012);
    table.insert("Viper", 5674);
    table.insert("Redstoner", 1890);
    table.insert("Marcel", 9231);
    table.insert("Danteh", 4562);
    table.insert("Huahwi", 8812);
    table.insert("Tayber", 1563);
    table.insert("Cxlvxn", 6732);
    table.insert("Minemanner", 2987);
    table.insert("Wallibear", 9832);
    table.insert("Luvonox", 7421);
    table.insert("Zilla", 5567);
    table.insert("Tryhard", 8234);
    table.insert("RKY", 3145);
    table.insert("Versace", 6451);
    table.insert("BastiGHG", 7734);
    table.insert("Target", 9012);
    table.insert("Straight", 6543);
    table.insert("Speeeedy", 2109);
    table.insert("BedlessNoob", 7642);
    table.insert("mrekk", 9832);
    table.insert("WhiteCat", 7421);
    table.insert("vaxei", 5567);
    table.insert("lifeline", 8234);
    table.insert("Shigetora", 3145);
    table.insert("btmc", 6451);
    table.insert("aetrna", 1892);
    table.insert("akolibed", 7734);
    table.insert("Mathi", 4321);
    table.insert("Rafis", 9012);
    table.insert("FlyingTuna", 6543);
    table.insert("RyuK", 5876);
    table.insert("Karthy", 7642);
    table.insert("Alumetri", 9432);
    table.insert("Varvalian", 3214);
    table.insert("Abyssal", 5678);
    table.insert("WubWoofWolf", 1245);
    table.printTable();
    table.search("foo"); //does not exist
    table.search("Technoblade"); //exists
    table.remove("FurryEBoy");
    table.remove("mrekk");
    table.remove("Illumina");
    table.search("Illumina");
    */

    //experimental analysis
    /*
    table.insert("real", 1302);
    table.insert("fake", 5741);
    table.insert("impartial", 892);
    table.insert("spin_0001", 9044);
    table.insert("spin_0002", 3117);
    table.insert("spin_0004", 6589);
    table.insert("spin_0005", 245);
    table.insert("spin_0006", 4812);
    table.insert("reader1", 7320);
    table.insert("reader2", 156);
    table.insert("reader3", 8234);
    table.insert("reader4", 4109);
    table.insert("reader5", 2977);
    table.insert("reader6", 5033);
    table.insert("abstract", 9812);
    table.insert("null", 614);
    table.insert("volatile", 3488);
    table.insert("struct", 7201);
    table.insert("nullptr", 1925);
    table.insert("endl", 4467);
    */

    table.printTable();

    return 0;
}

int HashTable::hashFunction(const string& key) const {
    const int prime = 31;
    unsigned long long hash = 0;

    for (char c : key) {
        hash = hash * prime + c;
    }

    return hash % capacity;
}

void HashTable::rehash() {
    vector <list<pair<string, int>>> temp = table; // create another table that copies the original table

    capacity *= 2; // double the capacity

    table.clear(); // clear the main table
    table.resize(capacity);
    currentSize = 0;
    collisionCount = 0;

    for (auto& bucket : temp) { // for every added bucket in the temp table,
        for (auto& element : bucket)  { // add the bucket back into the table
            insert(element.first, element.second);
        }
    }
}

void HashTable::insert(const string& key, int value) {
    int index = hashFunction(key); // the key is hashed and then assigned to index

    if (loadFactor() >= 0.75) {
        rehash();
        cout << "rehash!" << endl;
    }

    for (auto& pair : table[index]) { // go through every pair
        if (pair.first == key) { //if the key matches with another key in the list
                pair.second = value; // reassign the second value in the key,pair
                return;
        }
    } 

    if (!table[index].empty()) { // if there is a collision, increase the count 
        ++collisionCount;
        cout << "bop!" << endl;
    }

    table[index].push_back({key, value}); //insert at the end of the table
    ++currentSize;
}

bool HashTable::remove(const string& key) {
    int index = hashFunction(key); // the key is hashed and then assigned to index
    auto& bucket = table[index]; //reference to each list

    for (auto element = bucket.begin(); element != bucket.end(); ++element) { // go through every pair
        if (element->first == key) { //if a match is found,
            cout << "Goodbye, " << key << "!" << endl;
            bucket.erase(element);
            --currentSize; //decrease the size of the bucket
            return true;
        }
    }

    cout << key << " does not exist." << endl;
    return false;
}
int HashTable::search(const string& key) const {
    int index = hashFunction(key); // the key is hashed and then assigned to index;

    for (const auto& pair : table[index]) {
        if (pair.first == key) {
            cout << key << " has been found!" << endl;
            return pair.second; // Return the value if key is found
        }
    }
    
    cout << key << " does not exist." << endl;
    return 0;
}
double HashTable::loadFactor() const {
    if (capacity == 0) { // no dividing by 0
        return 0.0;
    }
    return static_cast<double>(currentSize) / capacity; //todo: make sum/size
    // n/m where n= average of keys, m= buckets
}
int HashTable::size() const {
    return currentSize;
}
bool HashTable::isEmpty() const {
    if (currentSize == 0) { // if there are no lists, return true
        return 1;
    }
    return 0;
}
void HashTable::printTable() const {
    int count = 0;

    for (int i=0; i < capacity; ++i) {  // go through every bucket (capacity)
        cout << "Bucket " << i << ": "; // print the bucket's index, 

        if (table[i].empty()) { // if the bucket is empty, print [empty]
            cout << " [empty] ";
        }
        else {
            for (const auto& pair: table[i]) { //iterate through every bucket at table index i
                ++count;
                cout << "{" << pair.first << ": " << pair.second << "} - "; //print the bucket's list
            }
            cout << "end"; // signifies the end of the current bucket
        }
        cout << endl;
    }
    cout << "Collisions: " << collisionCount << endl;
    cout << "Elements: " << count << endl;
    cout << "Load Factor: " << loadFactor() << endl;
    cout << "Table Capacity: " << size() << endl;

}
```
