class MedianFinder {
public:
    priority_queue<int>maxHeap; 
    priority_queue<int, vector<int>, greater<int>>minHeap; 
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //push into maxHeap first
        maxHeap.push(num); 
        // balance order
        if(!minHeap.empty() && maxHeap.top() > minHeap.top()){

            int a = maxHeap.top(); 
            maxHeap.pop(); 
            int b = minHeap.top(); 
            minHeap.pop(); 
            maxHeap.push(b); 
            minHeap.push(a); 

        }
      //  balance size; 
      if(maxHeap.size() > minHeap.size() +1){
        minHeap.push(maxHeap.top()); 
        maxHeap.pop(); 
      }
      else if(minHeap.size() > maxHeap.size()){
        maxHeap.push(minHeap.top()); 
        minHeap.pop(); 
      }

    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()){
            return maxHeap.top(); 
        }
        else{
            return (maxHeap.top() + minHeap.top())/2.0; 
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */