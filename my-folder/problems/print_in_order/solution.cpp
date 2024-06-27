class Foo {
    int turn;
    int i;
public:
    Foo() {
        turn  = 1;
        i = 0;
    }

    void first(function<void()> printFirst) {
        while(turn  != 1)
        {
            i = 1;
            cout<<i<<endl;
        }
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        turn = 2;
    }

    void second(function<void()> printSecond) {
        while(turn != 2)
        {
            i = 2;
            cout<<i<<endl;
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        turn = 3;
    }

    void third(function<void()> printThird) {
        while(turn != 3)
        {
            i = 3;
            cout<<i<<endl;
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();

        turn = 1;
    }
};