#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <queue>
#include <stack>
#include <utility>

using namespace std;


class Plant {
  public:
    //Creates a plant object with minimal info
    Plant(string name, int hum, int hard, int water);
    //Creates a plant object with all of the info
    Plant(string name, int hum, int hard, string size, int water,
          float light, int per, int maintenance);
    //Destructor
    virtual ~Plant();
    //Get methods to retrieve the various parts of the plant information
    virtual string getName();
    virtual int getHumidity();
    virtual int getHardiness();
    virtual string getSize();
    virtual int getWaterFreq();
    virtual float getLightRatio();
    virtual int getGrowingPer();
    virtual int getMaintenanceLevel();
  private:
    string name;
    //Ideal humidity
    int humidity;
    //Ideal temperature range
    int hardinessZone;
    //Size of the plant: small, medium, or large
    string size;
    //How frequently, in days per week, the plant needs water
    int waterFrq;
    //The ratio of how much light the plant needs per day
    float lightRatio;
    //How long the plant takes to grow
    int growingPer;
    //How intensive the plant is to maintain
    int maintenanceLevel;
};
//Implementations
Plant::Plant(string name, int hum, int hard, int water) {
  this->name = name;
  this->humidity = hum;
  this->hardinessZone = hard;
  this->size = "";
  this->waterFrq = water;
  this->lightRatio = 0;
  this->growingPer = 0;
  this->maintenanceLevel = 0;
}
Plant::Plant(string name, int hum, int hard, string size, int water,
      float light, int per, int maintenance) {
  this->name = name;
  this->humidity = hum;
  this->hardinessZone = hard;
  this->size = size;
  this->waterFrq = water;
  this->lightRatio = light;
  this->growingPer = per;
  this->maintenanceLevel = maintenance;
}
Plant::~Plant() {

}
string Plant::getName() {
  return this->name;
}
int Plant::getHumidity() {
  return this->humidity;
}
int Plant::getHardiness() {
  return this->hardinessZone;
}
string Plant::getSize() {
  return this->size;
}
int Plant::getWaterFreq() {
  return this->waterFrq;
}
float Plant::getLightRatio() {
  return this->lightRatio;
}
int Plant::getGrowingPer() {
  return this->growingPer;
}
int Plant::getMaintenanceLevel() {
  return this->maintenanceLevel;
}

class Zipcode {
  public:
    //Creates a zipcode object with environmental data
    Zipcode(int code, int hum, int hard, float rain);
    //Destructor
    virtual ~Zipcode();
    //Get methods for all of the environmental data
    virtual int getZipcode();
    virtual int getZipHumidity();
    virtual int getZipHardiness();
    virtual float getRainFreq();
  private:
    int code;
    //The average humidity
    int humidity;
    //The average temperature expressed as a range
    int hardinessZone;
    //The frequency of rain, in days per week
    float rainFreq;
};
//Implementations
Zipcode::Zipcode(int code, int hum, int hard, float rain) {
  this->code = code;
  this->humidity = hum;
  this->hardinessZone = hard;
  this->rainFreq = rain;
}
Zipcode::~Zipcode() {

}
int Zipcode::getZipcode() {
  return this->code;
}
int Zipcode::getZipHumidity() {
  return this->humidity;
}
int Zipcode::getZipHardiness() {
  return this->hardinessZone;
}
float Zipcode::getRainFreq() {
  return this->rainFreq;
}
//Dictionary ADT
template <typename K, typename V> class Dictionary {
  public:
    virtual ~Dictionary() {
    }

    /**
     * Returns the size of the dictionary.
     * @return The number of key-value pairs in the data structure.
     */
    virtual int getSize() = 0;

    /**
     * Returns true if the dictionary is empty.
     * @return true if there are no elements in the dictionary.
     */
    virtual bool isEmpty() = 0;

    /**
     * Inserts the key-value pair into the dictionary
     * @param key The key for the new mapping.
     * @param value The value to associate with that key.
     * @throws runtime_error If they key already exists.
     */
    virtual void insert(K key, V value) = 0;

    /**
     * Finds the element indexed by the given key and updates its value to the
     * provided value parameter.
     * @param key The key of the mapping to update.
     * @param value The new value to associate with that key.
     * @throws runtime_error if the key is not found in the dictionary.
     */
    virtual void update(K key, V value) = 0;

    /**
     * Returns the value associated with the given key
     * @param key The key of the mapping to find.
     * @return The value associated with that key.
     * @throws runtime_error If the key is not found in the dictionary.
     */
    virtual V get(K key) = 0;

    /**
     * Determines if a given key exists in a mapping in this dictionary.
     * @param key The key to look for.
     * @return true if item in the dictionary has this key.
     */
    virtual bool contains(K key) = 0;

    /**
     * Deletes the element with given key from the dictionary.
     * @param key The key to remove.
     * @throws runtime_error If they key was not already in this dictionary.
     */
    virtual void remove(K key) = 0;

    /**
     * Obtains a vector containing all keys in this dictionary.
     * @return An STL vector object containing the keys in this
     *        dictionary (in no particular order).
     */
    virtual vector<K> getKeys() = 0;

    /**
     * Obtains a vector containing all key-value pairs in this dictionary.
     * @return An STL vector object containing the key-value pairs
     *     in the dictionary (in no particular order).
     */
    virtual vector<pair<K, V>> getItems() = 0;

  public:
    Dictionary() {
    }

  private:
    Dictionary(const Dictionary& other) = delete;
    Dictionary& operator=(const Dictionary& other) = delete;
};
//Linear Dictionary Declaration and Implementations
template <typename K, typename V>
class LinearDictionary : public Dictionary<K, V> {
  public:
    /**
     * Creates a new, empty LinearDictionary.
     */
    LinearDictionary();

    /**
     * Cleans up this LinearDictionary.
     */
    ~LinearDictionary();
    int getSize();
    bool isEmpty();
    void insert(K key, V value);
    void update(K key, V value);
    V get(K key);
    bool contains(K key);
    void remove(K key);
    vector<K> getKeys();
    vector<pair<K, V>> getItems();

  private:
    vector<pair<K, V>> list;
};

/**
 * removes an element from an arbitrary index in the vector
 * @param list vector to remove element from
 * @param index offset into vector where element to be removed resides
 * @return none, but list is modified
 * @throw runtime_error if index is out of range
 */
template <typename T> void removeFromVector(vector<T> &list, int index);
template <typename K, typename V> LinearDictionary<K, V>::LinearDictionary() {
  //Constructor
    this->list = vector<pair<K,V>>();
}

template <typename K, typename V> LinearDictionary<K, V>::~LinearDictionary() {

}

template <typename K, typename V> int LinearDictionary<K, V>::getSize() {
  //Returns the amount of elements stored
    return this->list.size();
}

template <typename K, typename V> bool LinearDictionary<K, V>::isEmpty() {
  //Returns if the LinearDictionary is empty
    return this->list.empty();
}

template <typename K, typename V>
void LinearDictionary<K, V>::insert(K key, V value) {
  //Inserts into the LinearDictionary
    for(int i = 0; i < this->list.size(); i++){
      if(this->list[i].first == key){
        throw runtime_error("Key already exists");
      }
    }
    pair<K,V> toAdd = pair<K,V>(key, value);
    this->list.push_back(toAdd);
}

template <typename K, typename V>
void LinearDictionary<K, V>::update(K key, V value) {
  //Changes key's current value with value
    for(int i = 0; i < this->list.size(); i++){
      if(this->list[i].first == key){
        this->list[i].second = value;
        return;
      }
    }
    throw runtime_error("Key does not exist");
}

template <typename K, typename V> V LinearDictionary<K, V>::get(K key) {
  //Retrieves the value associated with key
  for(int i = 0; i < this->list.size(); i++){
    if(this->list[i].first == key){
      return this->list[i].second;
    }
  }
  throw runtime_error("Key does not exist");
}

template <typename K, typename V> bool LinearDictionary<K, V>::contains(K key) {
  //Checks if the LinearyDictionary contains key
  for(int i = 0; i < this->list.size(); i++){
    if(this->list[i].first == key){
      return true;
    }
  }
  return false;
}

template <typename K, typename V> void LinearDictionary<K, V>::remove(K key) {
  //Removes the key and its associated value
    int index = this->list.size();
    for(int i = 0; i < this->list.size(); i++){
      if(this->list[i].first == key){
        index = i;
      }
    }
    if(index == this->list.size()){
      throw runtime_error("Key does not exist");
    }
    removeFromVector(this->list, index);
}

template <typename K, typename V> vector<K> LinearDictionary<K, V>::getKeys() {
  //Returns a vector of every key in the LinearDictionary
    vector<K> returnV;
    for(int i = 0; i < this->list.size(); i++){
      returnV.push_back(this->list[i].first);
    }
    return returnV;
}

template <typename K, typename V>
vector<pair<K, V>> LinearDictionary<K, V>::getItems() {
  //Returns a vector of every pair of keys and their values
  return this->list;
}

template <typename T> void removeFromVector(vector<T> &list, int index){
  if(index < 0 || index >= list.size()){
    throw runtime_error("index out of range in removeFromVector");
  }
  list.erase(list.begin()+index, list.begin()+index+1);
}
//Declarations for Hash Functions
int hashInt(int value, int range);
int hashString(string value, int range);
//Hash Function implementations for the use of the HashTables
int hashInt(int value, int range) {
    int toReturn = value % range;
    if (toReturn < 0) {
        toReturn += range;
    }
    return toReturn;
}
int hashString(string value, int range) {
    int hash_value = 0;
    for (int i = 0; i < value.length(); i++) {
        hash_value *= 31;       // prime number helps to avoid hash collisions
        hash_value += value[i]; // remember: characters can be treated as ints
    }

    // now, compress down to range
    int toReturn = hash_value % range;
    if (toReturn < 0) {
        toReturn += range;
    }
    return toReturn;
}
//HashTable declaration for zipcodes specifically
class ZipHashTable : public Dictionary<int, Zipcode*> {
  public:
    /**
     * Creates a new HashTable with a maximum load factor of 0.75.
     */
    ZipHashTable();

    /**
     * Creates a new HashTable.
     * @param maxLoadFactor The maximum load factor which will be permitted
     *                      before this hash table changes its capacity.
     */
    ZipHashTable(float maxLoadFactor);
    /**
     * Cleans up this HashTable.
     */
    ~ZipHashTable();
    // Dictionary ADT Methods.
    int getSize();
    bool isEmpty();
    void insert(int key, Zipcode* value);
    void update(int key, Zipcode* value);
    Zipcode* get(int key);
    bool contains(int key);
    void remove(int key);
    vector<int> getKeys();
    vector<pair<int, Zipcode*>> getItems();
  private:
    //Doubles the capacity of the table in order to reduce the load factor.
    void expandCapacity();
    float maxLoadFactor;
    int capacity;
    int size;
    LinearDictionary<int,Zipcode*>* table;
};
ZipHashTable::ZipHashTable() {
  //Constructor
    this->maxLoadFactor = 0.75;
    this->capacity = 5;
    this->table = new LinearDictionary<int,Zipcode*>[this->capacity];
    this->size = 0;
}

ZipHashTable::ZipHashTable(float maxLoadFactor) {
  //Constructor
    this->maxLoadFactor = maxLoadFactor;
    this->capacity = 5;
    this->table = new LinearDictionary<int,Zipcode*>[this->capacity];
    this->size = 0;
}

ZipHashTable::~ZipHashTable() {
  //Destructor
    delete[] this->table;
}

int ZipHashTable::getSize() {
  //Returns the number of items actually stored in the hash table
    return this->size;
}

bool ZipHashTable::isEmpty() {
  //Returns true if there is nothing stored in the hash table, false otherwise
    return this->size == 0;
}

void ZipHashTable::insert(int key, Zipcode* value) {
  //Adds a key,value pair to the hash table.
  //@param key - new key added
  //@param value - new value added
    int index = hashInt(key, this->capacity);
    this->table[index].insert(key, value);
    this->size++;
    float loadFactor = (float)this->size/this->capacity;
    if(loadFactor >= this->maxLoadFactor){
      expandCapacity();
    }
}

void ZipHashTable::update(int key, Zipcode* value) {
  //Changes the value associated with an existing key.
  //@param key - the key we are updating
  //@param value - the new value
  int index = hashInt(key, this->capacity);
  this->table[index].update(key, value);
}

Zipcode* ZipHashTable::get(int key) {
  //Retrieves the value of a key.
  //@param key - the key whose value we want
  if(this->size == 0){
    throw runtime_error("HashTable is empty");
  }
  int index = hashInt(key, this->capacity);
  Zipcode* returnV = this->table[index].get(key);
  return returnV;
}

bool ZipHashTable::contains(int key) {
  //Checks to see if the key exists in the hash Hash table
  //@param key - the key we are checking for
  int index = hashInt(key, this->capacity);
  return this->table[index].contains(key);
}

void ZipHashTable::remove(int key) {
  //Deletes a key,value pair from the hash table
  //@param key - the key we are deleting
  int index = hashInt(key, this->capacity);
  this->table[index].remove(key);
  this->size--;
}

vector<int> ZipHashTable::getKeys() {
  //Retrieves all the keys in the hash table
  vector<int> list;
  for(int i = 0; i < this->capacity; i++){
    vector<int> current = this->table[i].getKeys();
    list.insert(list.end(), current.begin(), current.end());
  }
  return list;
}
vector<pair<int, Zipcode*>> ZipHashTable::getItems() {
  //Retrieve all the key,value pairs stored in the hash table
  vector<pair<int, Zipcode*>> list;
  for(int i = 0; i < this->capacity; i++){
    vector<pair<int, Zipcode*>> current = this->table[i].getItems();
    list.insert(list.end(), current.begin(), current.end());
  }
  return list;
}

void ZipHashTable::expandCapacity() {
  //Doubles the size of our hash table array.
  vector<pair<int,Zipcode*>> allItems = getItems();
  //store all the items currently in our hash table
  this->capacity *= 2;
  delete[] this->table; //delete old table
  this->table = new LinearDictionary<int,Zipcode*>[this->capacity];
  int vectorSize = allItems.size();
  for(int i = 0; i < vectorSize; i++){
    pair<int, Zipcode*> pair = allItems[i];
    insert(pair.first, pair.second);
    this->size --; //insert increases size, but we aren't adding any new items
  }
}
//HashTable declaration for plants specifically
class PlantHashTable : public Dictionary<string, Plant*> {
  public:
    /**
     * Creates a new HashTable with a maximum load factor of 0.75.
     */
    PlantHashTable();

    /**
     * Creates a new HashTable.
     * @param maxLoadFactor The maximum load factor which will be permitted
     *                      before this hash table changes its capacity.
     */
    PlantHashTable(float maxLoadFactor);
    /**
     * Cleans up this HashTable.
     */
    ~PlantHashTable();

    // Dictionary ADT Methods.
    int getSize();
    bool isEmpty();
    void insert(string key, Plant* value);
    void update(string key, Plant* value);
    Plant* get(string key);
    bool contains(string key);
    void remove(string key);
    vector<string> getKeys();
    vector<pair<string, Plant*>> getItems();

  private:
    //Doubles the capacity of the table in order to reduce the load factor.
    void expandCapacity();
    float maxLoadFactor;
    int capacity;
    int size;
    LinearDictionary<string,Plant*>* table;

};
PlantHashTable::PlantHashTable() {
  //Constructor
    this->maxLoadFactor = 0.75;
    this->capacity = 5;
    this->table = new LinearDictionary<string,Plant*>[this->capacity];
    this->size = 0;
}

PlantHashTable::PlantHashTable(float maxLoadFactor) {
  //Constructor
    this->maxLoadFactor = maxLoadFactor;
    this->capacity = 5;
    this->table = new LinearDictionary<string,Plant*>[this->capacity];
    this->size = 0;
}

PlantHashTable::~PlantHashTable() {
  //Destructor
    delete[] this->table;
}

int PlantHashTable::getSize() {
  //Returns the number of items actually stored in the hash table
    return this->size;
}

bool PlantHashTable::isEmpty() {
  //Returns true if there is nothing stored in the hash table, false otherwise
    return this->size == 0;
}

void PlantHashTable::insert(string key, Plant* value) {
  //Adds a key,value pair to the hash table.
  //@param key - new key added
  //@param value - new value added
    int index = hashString(key, this->capacity);
    this->table[index].insert(key, value);
    this->size++;
    float loadFactor = (float)this->size/this->capacity;
    if(loadFactor >= this->maxLoadFactor){
      expandCapacity();
    }
}

void PlantHashTable::update(string key, Plant* value) {
  //Changes the value associated with an existing key.
  //@param key - the key we are updating
  //@param value - the new value
  int index = hashString(key, this->capacity);
  this->table[index].update(key, value);
}

Plant* PlantHashTable::get(string key) {
  //Retrieves the value of a key.
  //@param key - the key whose value we want
  if(this->size == 0){
    throw runtime_error("HashTable is empty");
  }
  int index = hashString(key, this->capacity);
  Plant* returnV = this->table[index].get(key);
  return returnV;
}

bool PlantHashTable::contains(string key) {
  //Checks to see if the key exists in the hash Hash table
  //@param key - the key we are checking for
  int index = hashString(key, this->capacity);
  return this->table[index].contains(key);
}

void PlantHashTable::remove(string key) {
  //Deletes a key,value pair from the hash table
  //@param key - the key we are deleting
  int index = hashString(key, this->capacity);
  this->table[index].remove(key);
  this->size--;
}

vector<string> PlantHashTable::getKeys() {
  //Retrieves all the keys in the hash table
  vector<string> list;
  for(int i = 0; i < this->capacity; i++){
    vector<string> current = this->table[i].getKeys();
    list.insert(list.end(), current.begin(), current.end());
  }
  return list;
}
vector<pair<string, Plant*>> PlantHashTable::getItems() {
  //Retrieve all the key,value pairs stored in the hash table
  vector<pair<string, Plant*>> list;
  for(int i = 0; i < this->capacity; i++){
    vector<pair<string, Plant*>> current = this->table[i].getItems();
    list.insert(list.end(), current.begin(), current.end());
  }
  return list;
}
void PlantHashTable::expandCapacity() {
  //Doubles the size of our hash table array.
  vector<pair<string,Plant*>> allItems = getItems();
  //store all the items currently in our hash table
  this->capacity *= 2;
  delete[] this->table; //delete old table
  this->table = new LinearDictionary<string,Plant*>[this->capacity];
  int vectorSize = allItems.size();
  for(int i = 0; i < vectorSize; i++){
    pair<string, Plant*> pair = allItems[i];
    insert(pair.first, pair.second);
    this->size --; //insert increases size, but we aren't adding any new items
  }
}
//PriorityQueue declaration
template <typename P, typename V> class PriorityQueue {
  public:
    virtual ~PriorityQueue(){};

    /**
     * Adds an item with given priority and value to this priority queue.  The
     * meaning of this priority is dependent upon the implementation.
     * @param priority The priority of the item being added.
     * @param value The value to store in the queue at that priority.
     */
    virtual void insert(P priority, V value) = 0;

    /**
     * Removes the next item from this priority queue and returns its value.
     * The "next" item is based upon the priority with which it was added to the
     * queue; the meaning of that priority is left up to the implementation.
     * @return The value of the removed item.
     * @throws runtime_error if there are no items in the priority queue.
     */
    virtual V remove() = 0;

    /**
     * Retrieves the next item from this queue (without removing it).
     * @return The value of the next item.
     * @throws runtime_error If there are no items in the priority queue.
     */
    virtual V peek() = 0;

    /**
     * Retrieves the priority of the next item in the queue.
     * @return The priority of the next item in the queue.
     * @throws runtime_error if there are no items in the priority queue.
     */
    virtual P peekPriority() = 0;

    /**
     * Determines the number of elements in the priority queue.
     * @return The number of elements in the priority queue.
     */
    virtual int getSize() = 0;

    /**
     * Determines whether this priority queue is empty.
     * @return true if the priority
     */
    virtual bool isEmpty() = 0;

  public:
    PriorityQueue() {
    }

};
template <typename T, typename U> class FirstLess {
  public:
    bool operator()(pair<T, U> a, pair<T, U> b);
};

template <typename T, typename U>
bool FirstLess<T, U>::operator()(pair<T, U> a, pair<T, U> b) {
    return a.first < b.first;
}

/**
 * An implementation of a max-priority queue.  The take and peek methods of this
 * priority queue will return the elements with the highest priority values
 * first.
 */
template <typename P, typename V>
class STLMaxPriorityQueue : public PriorityQueue<P, V> {
  public:
    /**
     * Creates a new, empty max-heap priority queue.
     */
    STLMaxPriorityQueue();
    /**
     * Creates a new max-heap priority queue which contains the provided values
     * at their associated priorities.  This constructor heapifies the vector
     * and so runs in O(n) time.
     * @param contents The initial contents of the priority queue.
     */
    STLMaxPriorityQueue(vector<pair<P, V>> contents);
    ~STLMaxPriorityQueue();
    void insert(P priority, V value);
    V remove();
    V peek();
    P peekPriority();
    int getSize();
    bool isEmpty();

  private:
    std::priority_queue<pair<P, V>, vector<pair<P, V>>, FirstLess<P, V>>*
        actualPriorityQueue;

};

template <typename P, typename V>
STLMaxPriorityQueue<P, V>::STLMaxPriorityQueue() {
    actualPriorityQueue =
        new std::priority_queue<pair<P, V>, vector<pair<P, V>>,
                                FirstLess<P, V>>();
}

template <typename P, typename V>
STLMaxPriorityQueue<P, V>::STLMaxPriorityQueue(vector<pair<P, V>> contents) {
    actualPriorityQueue =
        new std::priority_queue<pair<P, V>, vector<pair<P, V>>,
                                FirstLess<P, V>>(contents.begin(),
                                                 contents.end());
}

template <typename P, typename V>
STLMaxPriorityQueue<P, V>::~STLMaxPriorityQueue() {
    delete actualPriorityQueue;
}

template <typename P, typename V>
void STLMaxPriorityQueue<P, V>::insert(P priority, V value) {
    actualPriorityQueue->push(pair<P, V>(priority, value));
}

template <typename P, typename V> V STLMaxPriorityQueue<P, V>::remove() {
    if (actualPriorityQueue->empty()) {
        throw runtime_error("STLMaxPriorityQueue::remove(): empty prio queue");
    }
    V v = actualPriorityQueue->top().second;
    actualPriorityQueue->pop();
    return v;
}

template <typename P, typename V> V STLMaxPriorityQueue<P, V>::peek() {
    if (actualPriorityQueue->empty()) {
        throw runtime_error("STLMaxPriorityQueue::peek(): empty prio queue");
    }
    return actualPriorityQueue->top().second;
}

template <typename P, typename V> P STLMaxPriorityQueue<P, V>::peekPriority() {
    if (actualPriorityQueue->empty()) {
        throw runtime_error(
            "STLMaxPriorityQueue::peekPriority(): empty prio queue");
    }
    return actualPriorityQueue->top().first;
}

template <typename P, typename V> int STLMaxPriorityQueue<P, V>::getSize() {
    return actualPriorityQueue->size();
}

template <typename P, typename V> bool STLMaxPriorityQueue<P, V>::isEmpty() {
    return actualPriorityQueue->empty();
}
/*Compare function cross checks the given zip code with all plants in the
database for matching features*/
STLMaxPriorityQueue<int, string>
compare(PlantHashTable* plants, ZipHashTable* zips, int code) {
  Zipcode* ourZip = zips->get(code);
  vector<pair<string, Plant*>> all = plants->getItems();
  int size = all.size();
  STLMaxPriorityQueue<int, string> returnV = STLMaxPriorityQueue<int, string>();
  for(int i = 0; i < size; i++) {
    int match = 0;
    if (ourZip->getZipHumidity() <= all[i].second->getHumidity() + 5 &&
        ourZip->getZipHumidity() >= all[i].second->getHumidity() - 5){
      match += 2;
    }
    else if(ourZip->getZipHumidity() <= all[i].second->getHumidity() + 15 &&
            ourZip->getZipHumidity() >= all[i].second->getHumidity() - 15) {
      match += 1;
    }
    if (ourZip->getZipHardiness() <= all[i].second->getHardiness() + 1 &&
        ourZip->getZipHardiness() >= all[i].second->getHardiness() - 1) {
      match += 2;
    }
    else if(ourZip->getZipHardiness() <= all[i].second->getHardiness() + 3 &&
            ourZip->getZipHardiness() >= all[i].second->getHardiness() - 3) {
      match += 1;
    }
    if(ourZip->getRainFreq() == all[i].second->getWaterFreq()) {
      match += 2;
    }
    else if(ourZip->getRainFreq() <= all[i].second->getWaterFreq() + 1 &&
            ourZip->getRainFreq() >= all[i].second->getWaterFreq() - 1) {
      match += 1;
    }
    if(returnV.getSize() < 10) {
      returnV.insert(-1 * match, all[i].first);
    }
    else {
      if(returnV.peekPriority() > match){
        string dump = returnV.remove();
        returnV.insert(-1 * match, all[i].first);
      }
    }
  }
  return returnV;
}
//Instantiates the sample plant and zip code databases
PlantHashTable* instantiatePlants() {
  PlantHashTable* plants = new PlantHashTable();
  Plant* birdsNestFern = new Plant("Bird's Nest Fern", 40, 11, 7);
  Plant* ladyFern = new Plant("Lady Fern", 80, 6, 7);
  Plant* fiddleLeaf = new Plant("Fiddle Leaf", 45, 11, 3);
  Plant* tomato = new Plant("Tomato Plant", 70, 6, 7);
  Plant* nephrolepis = new Plant("Nephrolepis", 70, 6, 7);
  Plant* peperomia = new Plant("Peperomia", 60, 11, 2);
  Plant* cabbage = new Plant("Cabbage", 85, 7, 7);
  Plant* hibiscus = new Plant("Hibiscus", 75, 9, 7);
  Plant* kentiaPalm = new Plant("Kentia Palm", 85, 9, 5);
  Plant* desertRose = new Plant("Desert Rose", 10, 11, 1);
  Plant* sunflower = new Plant("Sunflower", 70, 5, 4);
  Plant* basil = new Plant("Basil", 500, 10, 5);
  plants->insert("Bird's Nest Fern", birdsNestFern);
  plants->insert("Lady Fern", ladyFern);
  plants->insert("Fiddle Leaf", fiddleLeaf);
  plants->insert("Tomato Plant", tomato);
  plants->insert("Nephrolepis", nephrolepis);
  plants->insert("Peperomia", peperomia);
  plants->insert("Cabbage", cabbage);
  plants->insert("Hibiscus", hibiscus);
  plants->insert("Kentia Palm", kentiaPalm);
  plants->insert("Desert Rose", desertRose);
  plants->insert("Sunflower", sunflower);
  plants->insert("Basil", basil);
  return plants;
}
ZipHashTable* instantiateZips() {
  ZipHashTable* zips = new ZipHashTable();
  Zipcode* zip19041 = new Zipcode(19041, 71, 7, 2);
  Zipcode* zip85001 = new Zipcode(85001, 36, 9, 0);
  zips->insert(19041, zip19041);
  zips->insert(85001, zip85001);
  return zips;
}
//Main file that sends out the results in cout
int main(int argc, char** argv){
  PlantHashTable* plants = instantiatePlants();
  ZipHashTable* zips = instantiateZips();
  string code = argv[1];
  int zCode = stoi(code);
  STLMaxPriorityQueue<int, string> topPlants = compare(plants, zips, zCode);
  int size = topPlants.getSize();
  stack<pair<string,int>> sol = stack<pair<string,int>>();
  for(int i = 0; i < size; i++) {
    string name = topPlants.peek();
    pair<string,int> myPair;
    myPair.first = name;
    myPair.second = topPlants.peekPriority() * -1;
    topPlants.remove();
    sol.push(myPair);
  }
  pair<string, int> number1 = sol.top();
  sol.pop();
  pair<string, int> number2 = sol.top();
  sol.pop();
  pair<string, int> number3 = sol.top();
  sol.pop();
  pair<string, int> number4 = sol.top();
  sol.pop();
  pair<string, int> number5 = sol.top();
  sol.pop();
  pair<string, int> number6 = sol.top();
  sol.pop();
  pair<string, int> number7 = sol.top();
  sol.pop();
  pair<string, int> number8 = sol.top();
  sol.pop();
  pair<string, int> number9 = sol.top();
  sol.pop();
  pair<string, int> number10 = sol.top();
  sol.pop();
  cout << number1.first << " " << number1.second << ", "
          << number2.first << " " << number2.second << ", "
          << number3.first << " " << number3.second << ", "
          << number4.first << " " << number4.second << ", "
          << number5.first << " " << number5.second << ", "
          << number6.first << " " << number6.second << ", "
          << number7.first << " " << number7.second << ", "
          << number8.first << " " << number8.second << ", "
          << number9.first << " " << number9.second << ", "
          << number10.first << " " << number10.second << endl;
  delete zips;
  delete plants;
  return 0;
}
