#pragma once

#include <iterator>
#include "../Graph.h"

/**
 * A base class for traversal algorithms on graph.
 */
class GraphTraversal {
    public:
        /**
         * A forward iterator through an GraphTraversal.
         */
        class Iterator : std::iterator<std::forward_iterator_tag, Node> {
            public:
                Iterator();

                Iterator & operator++();
                Node operator*();
                bool operator!=(const Iterator &other);

                // member functions
                Iterator(GraphTraversal* traversal, Node start);

            private:
                // private members
                Node start_;
                Node current_;
                
                // references
                GraphTraversal* traversal_;

                // helper function
                void addNext(Node node);
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
    virtual void add(const Node & t) = 0;
    /**
     * Remove and return the next point of the traversal
     * Virtual function. Derived class need to implement this
     */
    virtual Node pop() = 0;
    /**
     * Return but not remove the next point of the traversal
     * Virtual function. Derived class need to implement this
     */
    virtual Node peek() const = 0;
    /**
     * To see if the traversal has no points left
     * Virtual function. Derived class need to implement this
     */
    virtual bool empty() const = 0;
};