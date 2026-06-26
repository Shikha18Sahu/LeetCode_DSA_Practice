class LFUCache {
public:

    struct Node{
        int key;
        int value;
        int freq;

        Node(int k,int v){
            key = k;
            value = v;
            freq = 1;
        }
    };

    int capacity;
    int minFreq;

    unordered_map<int, list<Node>::iterator> keyMap;
    unordered_map<int, list<Node>> freqMap;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {

        if(keyMap.find(key)==keyMap.end())
            return -1;

        auto it = keyMap[key];

        int value = it->value;
        int freq = it->freq;

        freqMap[freq].erase(it);

        if(freqMap[freq].empty()){
            freqMap.erase(freq);
            if(minFreq==freq)
                minFreq++;
        }

        freqMap[freq+1].push_front(Node(key,value));
        freqMap[freq+1].front().freq = freq+1;

        keyMap[key]=freqMap[freq+1].begin();

        return value;
    }

    void put(int key, int value) {

        if(capacity==0)
            return;

        if(keyMap.find(key)!=keyMap.end()){

            keyMap[key]->value=value;
            get(key);
            return;
        }

        if(keyMap.size()==capacity){

            auto last = freqMap[minFreq].back();

            keyMap.erase(last.key);
            freqMap[minFreq].pop_back();

            if(freqMap[minFreq].empty())
                freqMap.erase(minFreq);
        }

        freqMap[1].push_front(Node(key,value));
        keyMap[key]=freqMap[1].begin();
        minFreq=1;
    }
};