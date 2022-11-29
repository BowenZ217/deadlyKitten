#pragma once

#include <iterator>
#include <vector>
#include <utility>
#include <algorithm>
#include "../Graph.h"

using std::vector;
using std::pair;

/**
 * A base class for traversal algorithms on graph.
 */
class GraphTraversal {
    public:
        /**
         * A forward iterator through an GraphTraversal.
         */
        class Iterator : std::iterator<std::forward_iterator_tag, Airport> {
            public:
                /**
                 * Default iterator constructor.
                 */
                Iterator();

                /**
                 * Three parameters constructor for Iterator class
                 * 
                 * @param traversal The traversal reference passed in
                 * @param start The start point of Iterator
                 * @param graph_ The graph reference passed in
                 */
                Iterator(GraphTraversal* traversal, int start, Graph* graph);

                /**
                 * Iterator increment opreator.
                 *
                 * Advances the traversal of the graph.
                 */
                Iterator & operator++();

                /**
                 * Iterator accessor opreator.
                 *
                 * Accesses the current airport in the ImageTraversal.
                 * 
                 * @return the current Airport
                 */
                Airport* operator*();

                /**
                 * Iterator inequality operator.
                 *
                 * Determines if two iterators are not equal.
                 */
                bool operator!=(const Iterator &other);


            private:
                // private members
                int start_;
                int current_;
                
                // references
                GraphTraversal* traversal_;
                Graph* graph_;

                // helper function
                void addNext(int index);
        };

    /**
     * The begining of an iterator
     * Virtual function. Derived class need to implement this
     */
    virtual Iterator begin() = 0;

    /**
     * The end of an iterator
     * Virtual function. Derived class need to implement this
     */
    virtual Iterator end() = 0;

    /**
     * Add new point to the traversal
     * Virtual function. Derived class need to implement this
     */
    virtual void add(int idx) = 0;
    /**
     * Remove and return the next point of the traversal
     * Virtual function. Derived class need to implement this
     */
    virtual int pop() = 0;
    /**
     * Return but not remove the next point of the traversal
     * Virtual function. Derived class need to implement this
     */
    virtual int peek() const = 0;
    /**
     * To see if the traversal has no points left
     * Virtual function. Derived class need to implement this
     */
    virtual bool empty() const = 0;
};