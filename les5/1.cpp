
void safe_div(int x, int y) {
    if (y == 0 ) throw DivByZero();
};

int main() {

    try {

    catch (DivByZero &ex)

    };

    return 0;
}
