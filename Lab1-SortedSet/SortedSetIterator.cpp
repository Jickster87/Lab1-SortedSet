#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
    currentPosition = 0;
}


void SortedSetIterator::first() {
    currentPosition = 0;
}


void SortedSetIterator::next() {
    if (currentPosition >= multime.sizeSet) {
        throw exception();
    }
    currentPosition++;
}


TElem SortedSetIterator::getCurrent()
{
    if (!valid()) {
        throw exception();
    };
    return multime.mainArray[currentPosition];
}

bool SortedSetIterator::valid() const {
    return currentPosition < multime.sizeSet;
}

