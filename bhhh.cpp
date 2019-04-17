//include library
#include<iostream>
using namespace std;
//define class for binary heap
class BinaryHeap{
	  public:
		     //defining pointer
             int *hArr;
		     //varaiable for the size of the array
		     int msize;
		     //variable for current size of the array
		     int csize;
		     //constructor
		     BinaryHeap(int max_size){
			                  hArr = new int[msize];
			                  msize = max_size;
                              csize = -1;
                              }
		     //function for swaaping
		     void swap(int &a, int &b){
			                        int temp = a;
			                        a = b;
			                        b = temp;
		                              }
		    //returning index of parent of node
		    int parent(int i){
			              return (i-1)/2;
		                 }
		    //returning index of left child of node
		    int left(int i){
			            return (i*2)+1;
		              }
		    //returning index of right child of node
            int right(int i){
			             return (i*2)+2;
		                   }
		    //returning the least element
            int getMin(){
			       return hArr[0];
		                   }
		    //function for insertion
		    void insert(int value){
			                if(csize == msize)
				                          return;
			                       hArr[++csize] = value;
			int i = csize;
			//looping
			while((i>-1) && (hArr[i] < hArr[parent(i)])){
				                                 swap(hArr[i],hArr[parent(i)]);
				                                 i = parent(i);
			                                              }
                                                        }
		     //function using recursion
             void min_heapify(int i){
			 //base case
			 if(hArr[parent(i)] < hArr[i])
				                        return;
			 //comparision
			 else if(hArr[left(i)] < hArr[right(i)]){
				                            //replacing with minimum child and heapifying
				                            swap(hArr[i],hArr[left(i)]);
				                            min_heapify(left(i));
			                                          }
			  else{
				   //replacing with minimum child and heapifying
				   swap(hArr[i],hArr[right(i)]);
				   min_heapify(right(i));
			      }
		          }
		      //displaying the binary heap
		      void display(){
                            for(int i=0; i<=csize; i++)
				                  cout<<hArr[i]<<",";
		                                }
		      //function that extracts minimum node i.e., the root and removes it from the heap
		      //heapifies the remaining heap to maintain condition of min heap
		      int extract_min(){
			               //Base case for empty heap
			               if(csize == -1)
				                        return 0;
			               //Base case for heap with 1 element
			               if(csize == 0){
                           return hArr[csize--];
			                  }
            int min = hArr[0];
			//placing last element in place of root
			hArr[0] = hArr[csize--];
			min_heapify(0);
			return min;
		    }
		    //function for decreasing the value of a node and then changeing the heap to maintain the condition of minimum heap
		    void decreaseKey(int i, int new_val){
			                             hArr[i] = new_val;
			                            //Looping
                                        while((i>-1) && (hArr[i] < hArr[parent(i)])){
				                                                    swap(hArr[i],hArr[parent(i)]);
				                                                    i = parent(i);
			                                            }
		                                                }
		    //function for deletion at index i
            void deleteKeyAt(int i){
			                  decreaseKey(i,hArr[0]-1);
			                  extract_min();
		                        }
};
//main function
int main(){
	BinaryHeap bh1(20);
	//looping
    for(int i = 10; i >0 ; i--){
        cout << "Inserting " << i << endl;
        bh1.insert(i);
        bh1.display();
    }
    cout<<endl;
    cout<<endl<<"After extracting minimum: \n";
    cout<<"The minimum element: "<<bh1.extract_min()<<endl;
    //displaying
    bh1.display();
    cout<<endl;
    cout<<"After deleting at index 3: \n";
    //deletion
    bh1.deleteKeyAt(3);
    //displaying
    bh1.display();
    cout << endl;
//closing the programme
return 0;
}
