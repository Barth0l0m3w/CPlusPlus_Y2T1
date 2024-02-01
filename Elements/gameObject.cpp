#include "gameObject.hpp"

GameObject::GameObject(std::string identifier) : identifier(identifier) {}

GameObject::GameObject(const GameObject &other) : identifier(other.getIdentifier()) {}

GameObject::~GameObject() {}


void GameObject::AddChildren(GameObject &child) {
    this->children.push_back(&child);
}

void GameObject::RemoveChildren(GameObject &child) {

    for (int i = 0; i < children.size(); ++i) {
        if (children[i] == &child) {
            children.erase(children.begin() + i);
            break;
        }
    }
}


std::string GameObject::getIdentifier() const {
    return this->identifier;
}