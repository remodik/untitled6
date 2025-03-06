#include <iostream>
#include <vector>
#include <memory>


class Living {
protected:
    int x, y;
    bool alive;

public:
    Living(const int x, const int y) : x(x), y(y), alive(true) {}

    virtual ~Living() = default;

    virtual void update(std::vector<std::vector<std::shared_ptr<Living>>>& world) = 0;

    bool isAlive() const {
        return alive;
    }

    void die() {
        alive = false;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void move(const int newX, const int newY) {
        x = newX;
        y = newY;
    }
};

class Grass final : public Living {
public:
    Grass(const int x, const int y) : Living(x, y) {}

    void update(std::vector<std::vector<std::shared_ptr<Living>>>& world) override {
        // Трава не делает ничего, кроме как существует
    }
};

class Rabbit final : public Living{
    int age;
    static constexpr int MAX_AGE = 5;

public:
    Rabbit(int x, int y) : Living(x, y), age(0) {}

    void update(std::vector<std::vector<std::shared_ptr<Living>>>& world) override {
        if (!alive) return;

        age++;
        if (age >= MAX_AGE) {
            die();
            return;
        }

        // Логика питания
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                const int newX = x + i;
                if (const int newY = y + j; newX >= 0 && newX < world.size() && newY >= 0 && newY < world[0].size()) {
                    auto& cell = world[newX][newY];
                    if (const auto grass = std::dynamic_pointer_cast<Grass>(cell)) {
                        grass->die();
                        return;
                    }
                }
            }
        }

        // Логика размножения
        int rabbitCount = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                const int newX = x + i;
                if (const int newY = y + j; newX >= 0 && newX < world.size() && newY >= 0 && newY < world[0].size()) {
                    if (std::dynamic_pointer_cast<Rabbit>(world[newX][newY])) {
                        rabbitCount++;
                    }
                }
            }
        }

        if (rabbitCount > 1) {
            // Размножение
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    int newX = x + i;
                    if (int newY = y + j; newX >= 0 && newX < world.size() && newY >= 0 && newY < world[0].size()) {
                        if (!world[newX][newY]) {
                            world[newX][newY] = std::make_shared<Rabbit>(newX, newY);
                            return;
                        }
                    }
                }
            }
        }
    }
};

class Fox final : public Living {
    int age;
    static constexpr int MAX_AGE = 7;
    static constexpr int MAX_FOXES = 5;

public:
    Fox(const int x, const int y) : Living(x, y), age(0) {}

    void update(std::vector<std::vector<std::shared_ptr<Living>>>& world) override {
        if (!alive) return;

        age++;
        if (age >= MAX_AGE) {
            die();
            return;
        }

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                const int newX = x + i;
                if (const int newY = y + j; newX >= 0 && newX < world.size() && newY >= 0 && newY < world[0].size()) {
                    auto& cell = world[newX][newY];
                    if (const auto rabbit = std::dynamic_pointer_cast<Rabbit>(cell)) {
                        rabbit->die();
                        return;
                    }
                }
            }
        }

        // Логика размножения
        int foxCount = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                const int newX = x + i;
                if (const int newY = y + j; newX >= 0 && newX < world.size() && newY >= 0 && newY < world[0].size()) {
                    if (std::dynamic_pointer_cast<Fox>(world[newX][newY])) {
                        foxCount++;
                    }
                }
            }
        }

        if (foxCount < MAX_FOXES) {
            // Размножение
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    int newX = x + i;
                    if (int newY = y + j; newX >= 0 && newX < world.size() && newY >= 0 && newY < world[0].size()) {
                        if (!world[newX][newY]) {
                            world[newX][newY] = std::make_shared<Fox>(newX, newY);
                            return;
                        }
                    }
                }
            }
        }
    }
};

class NoLife final : public Living {
public:
    NoLife(const int x, const int y) : Living(x, y) {}

    void update(std::vector<std::vector<std::shared_ptr<Living>>>& world) override {
        // Ничего не делает
    }
};

void visualize(const std::vector<std::vector<std::shared_ptr<Living>>>& world) {
    for (const auto& row : world) {
        for (const auto& cell : row) {
            if (std::dynamic_pointer_cast<Fox>(cell)) {
                std::cout << "F ";
            } else if (std::dynamic_pointer_cast<Rabbit>(cell)) {
                std::cout << "R ";
            } else if (std::dynamic_pointer_cast<Grass>(cell)) {
                std::cout << "G ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}

/*
int main() {
    constexpr int WORLD_SIZE = 10;
    std::vector<std::vector<std::shared_ptr<Living>>> world(WORLD_SIZE, std::vector<std::shared_ptr<Living>>(WORLD_SIZE));

    // Инициализация мира
    for (int i = 0; i < WORLD_SIZE; ++i) {
        for (int j = 0; j < WORLD_SIZE; ++j) {
            if (i % 2 == 0 && j % 2 == 0) {
                world[i][j] = std::make_shared<Grass>(i, j);
            } else if (i % 3 == 0 && j % 3 == 0) {
                world[i][j] = std::make_shared<Rabbit>(i, j);
            } else if (i % 5 == 0 && j % 5 == 0) {
                world[i][j] = std::make_shared<Fox>(i, j);
            } else {
                world[i][j] = std::make_shared<NoLife>(i, j);
            }
        }
    }

    // Симуляция
    for (int step = 0; step < 10; ++step) {
        for (int i = 0; i < WORLD_SIZE; ++i) {
            for (int j = 0; j < WORLD_SIZE; ++j) {
                if (world[i][j]) {
                    world[i][j]->update(world);
                }
            }
        }
    }

    visualize(world);

    return 0;
}*/
