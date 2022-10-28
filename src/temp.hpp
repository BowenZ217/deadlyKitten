

template <class T>
Foo<T>::Foo() {
    // init
    std::cout << "one Foo created." << std::endl;
}


template <class T>
void Foo<T>::foo(T something) {
    std::cout << "from Foo , input = " << something << std::endl;
}