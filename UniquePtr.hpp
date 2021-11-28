// Jest klasą szablonową
// Trzyma wskaźnik do zarządzanego obiektu
// Konstruktor kopiuje wskaźnik
// Destruktor zwalnia pamięć
// Kopiowanie jest niedozwolone
// Przenoszenie jest dozwolone i oznacza:
//     Skopiowanie wskaźnika z obiektu źródłowego
//     Ustawienie wskaźnika w obiekcie źródłowym na nullptr
// Wymagane metody: operator*(), operator->(), get(), release(), reset()

template<typename T>
class UniquePtr {
public:
    UniquePtr() {
        
    }

    explicit UniquePtr(T* ptr) {
        ptr_ = ptr;
    }

    UniquePtr(const UniquePtr& copy) = delete;

    UniquePtr(const UniquePtr&& move) {
        ptr_ = move.ptr_;
        move.ptr_ = nullptr;
    }

    ~UniquePtr() {
        if (ptr_) {
            delete ptr_;
        }
    }
    
    UniquePtr& operator=(const UniquePtr& copy) = delete;
    UniquePtr& operator=(const UniquePtr&& move) {
        if (move != ptr_) {
            ptr_ = std::move(move.ptr_);
        }
        return *ptr_;
    }

    T* operator*() {
        return ptr_;
    }

    T& operator->() {
        return ptr_;
    }

    T* get() {
        return ptr_;
    }

    T* release() {
        T* temp { *ptr_ };
        delete ptr_;
        return *temp;
    }

    void reset(T* data) {
        if (data != ptr_) {
            ptr_ = data;
        }
    }

private:
    T* ptr_ { nullptr };
};