#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "Box.h"

#include <ostream>
#include <vector>

/**
 * @brief takes in sized things and puts them into boxes.  stores
 * all the boxes internally
 * 
 */
class Warehouse {
public:
    /**
     * @brief Construct a new Warehouse object with
     * no boxes by default
     * 
     */
    Warehouse();
    /**
     * @brief puts the item into a Box of given size
     * @param SIZE size of the cube shaped box to store
     */
    void storeInBox(const int SIZE);
    /**
     * @brief Get the Box object at given position within the list
     * @param BOX_POS position within the list to retrieve
     * @return Box* pointer to the corresponding Box object
     */
    Box* getBox(const size_t BOX_POS) const;
    /**
     * @brief Get the number Of box objects
     * @return size_t number of boxes
     */
    size_t getNumberOfBoxes() const;
    /**
     * @brief retrieves the warehouse letter identifier
     * @return char warehouse letter identifier
     */
    char getWarehouseLetter() const;
    /**
     * @brief sets the warehouse letter identifier
     * @param warehouseLetter letter to identify warehouse by
     */
     void setWarehouseLetter(char warehouseLetter);

	 //overloaded constructors and destructors
	 //
	 //overwrites for assigning the same internal values of one warehouse to another upon inialization
	 Warehouse(const Warehouse& other) {
		//copies the letter from the last instance
		this->_warehouseLetter = other._warehouseLetter;
		
		//makes a vector of boxes
		this->_pBoxen = new std::vector<Box*>();

		//makes space for its values
		this->_pBoxen->reserve(other._pBoxen->size());
		
	     //copies each box values
		 for (Box* boxPtr : *(other._pBoxen)) {
			if (boxPtr != nullptr) {
				_pBoxen->push_back(new Box(*boxPtr)); 
			} else {
				_pBoxen->push_back(nullptr);
			}
		}
	 }
	 //copy constructor for copying boxes
	 Warehouse& operator = (const Warehouse& other) {
		//checks if they are the same warehouse
	 	if (this != &other) {
			//copies the letter
			this->_warehouseLetter = other._warehouseLetter;

			//deletes all boxes
			if (this->_pBoxen != nullptr) {
				for (Box* boxPtr : *(this->_pBoxen)) {
					delete boxPtr; // Clear out old boxes so they don't pile up or leak
				}
				delete this->_pBoxen;
			}

			//copies the pointer and boxes
			this->_pBoxen = new std::vector<Box*>();

			//reserves space for the new box
			this->_pBoxen->reserve(other._pBoxen->size());

			//loops over every box and copies the values from each box
			for (Box* boxPtr : *(other._pBoxen)) {
				//if there is box in a slot, replace it
				if (boxPtr != nullptr) {
					_pBoxen->push_back(new Box(*boxPtr)); 
				}
				else {
					_pBoxen->push_back(nullptr);
				}
			}
		 }
		 //gives the new warehouse vector
		 return *this;
	 }
	 //destructor
	 ~Warehouse() {
		if (_pBoxen != nullptr) {
		//deletes all boxes
		for(Box* boxptr: *_pBoxen) {
			delete boxptr;
		}
		//deletes the pointer to all boxes
		_pBoxen->clear();
		delete _pBoxen;
		_pBoxen = nullptr;
		}
	 }
private:
    /**
     * @brief holds a list of pointers to Boxes
     * 
     */
    std::vector<Box*>* _pBoxen;
    /**
     * @brief Warehouse letter identifier
     */
    char _warehouseLetter;
};

std::ostream& operator<<(std::ostream&, const Warehouse&);

#endif//WAREHOUSE_H
