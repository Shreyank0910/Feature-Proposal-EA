#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include <string>
#include <vector>

class GameObject {
private:
    int objectID;
    std::string objectName;
    // Coordinates for position (x, y, z) and size (width, height, depth)
    float position[3];
    float size[3];

public:
    GameObject(int id, const std::string& name, float x, float y, float z, float width, float height, float depth);
    virtual ~GameObject();

    // Getter and setter methods
    int getObjectID() const;
    std::string getObjectName() const;
    float* getPosition();
    float* getSize();

    // Methods for behavior
    virtual void resize(float newWidth, float newHeight, float newDepth) = 0;
};

class FurnitureObject : public GameObject {
private:
    int comfortLevel;

public:
    FurnitureObject(int id, const std::string& name, float x, float y, float z, float width, float height, float depth, int comfort);
    ~FurnitureObject();

    // Getter and setter methods
    int getComfortLevel() const;

    // Method for behavior
    void resize(float newWidth, float newHeight, float newDepth) override;
    void rotate(float degrees);
};

class DecorationObject : public GameObject {
private:
    std::string style;

public:
    DecorationObject(int id, const std::string& name, float x, float y, float z, float width, float height, float depth, const std::string& style);
    ~DecorationObject();

    // Getter and setter methods
    std::string getStyle() const;

    // Method for behavior
    void resize(float newWidth, float newHeight, float newDepth) override;
    void changeStyle(const std::string& newStyle);
};

class SimObject : public GameObject {
private:
    std::string age;
    int happiness;
    int energy;

public:
    SimObject(int id, const std::string& name, float x, float y, float z, float width, float height, float depth, const std::string& age, int happiness, int energy);
    ~SimObject();

    // Getter and setter methods
    std::string getAge() const;
    int getHappiness() const;
    int getEnergy() const;

    // Methods for behavior
    void resize(float newWidth, float newHeight, float newDepth) override;
    void moveTo(float x, float y, float z);
    void interactWith(GameObject* object);
};

class HouseObject {
private:
    std::vector<GameObject*> rooms;
    std::vector<FurnitureObject*> furniture;
    std::vector<DecorationObject*> decorations;

public:
    HouseObject();
    ~HouseObject();

    // Methods for behavior
    void addRoom(GameObject* room);
    void placeFurniture(FurnitureObject* furnitureObj, float x, float y, float z);
    void addDecoration(DecorationObject* decorationObj);
};

#endif // GAME_OBJECTS_H
