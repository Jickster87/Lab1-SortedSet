#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r) {
    setCapacity = 64;
    sizeSet = 0;
    mainArray = new TComp[setCapacity]();
    rel = r;
}


bool SortedSet::add(TComp elem) {
	//resize
    if (sizeSet == setCapacity) {
        setCapacity *= 2;
        TComp* tempArray = new TComp[setCapacity]();
        for (int i = 0; i < sizeSet; i++) {
            tempArray[i] = mainArray[i];
        }
        delete [] mainArray;
        mainArray = tempArray;
    }
    
    //if element already exists in the set return false
    for (int i = 0; i < sizeSet; i++) {
        if (mainArray[i] == elem) {
            return false;
        }
    }
    
    //if it doesnt exist insert according to rel
    //find index in main array and store value;
    int elemPos = 0;
    while (elemPos < sizeSet && rel(mainArray[elemPos], elem)) {
        elemPos++;
    }
    //shift from elemPos to end of bag;
    for (int i = sizeSet; i > elemPos; i--) {
        mainArray[i] = mainArray[i-1];
    }
    //insert elem at elemPos
    mainArray[elemPos] = elem;
    
    //final touches
    sizeSet++;
	return true;
}


bool SortedSet::remove(TComp elem) {
    // If the set is empty, return false
      if (sizeSet == 0) {
          return false;
      }
    
    //find elem
    int elemPos = -1;
    for (int i = sizeSet; i >= 0; i--) {
        if (mainArray[i] == elem) {
            elemPos = i;
            break;
        }
    }
    // not found get out
    if (elemPos == -1) {
            return false;
        }
    //shift all to overwrite
    for (int i = elemPos; i < sizeSet-1; i++) {
        mainArray[i] = mainArray[i+1];
    }
    sizeSet--;
    return true;
}


bool SortedSet::search(TComp elem) const {
    for (int i = 0; i < sizeSet; i++) {
        if (mainArray[i] == elem) {
            return true;
        }
    }
	return false;
}


int SortedSet::size() const {
	return sizeSet;
}



bool SortedSet::isEmpty() const {
	return sizeSet == 0;
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
    delete [] mainArray;
}


