#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <string>
#include <memory>
#include <unordered_map>
#include <iostream>
using namespace std;
class Resource {
public:
    virtual ~Resource() = default;
    virtual void load(const string& path) = 0;
    virtual void unload() = 0;
    virtual void display() const = 0;
};

class Texture final : public Resource {
    string textureData;

public:
    void load(const string& path) override {
        textureData = "Текстура загружена из " + path;
        cout << textureData << endl;
    }
    void unload() override {
        cout << "Текстура выгружена\n";
        textureData.clear();
    }

    void display() const override {cout << "Отображение текстуры: " << textureData << endl;}
};

class ResourceManager {
    unordered_map<string, unique_ptr<Resource>> resources;
public:
    ResourceManager() = default;
    ~ResourceManager() = default;

    template <typename T>
    void loadResource(const string& name, const string& path) {
        auto resource = make_unique<T>();
        resource->load(path);
        resources[name] = move(resource);
    }

    Resource* getResource(const string& name) {
        if (resources.contains(name)) return resources[name].get();
        return nullptr;
    }

    void unloadResource(const string& name) {
        if (resources.contains(name)) {
            resources[name]->unload();
            resources.erase(name);
        }
    }
};

#endif
