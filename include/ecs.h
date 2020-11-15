#pragma once

#include <algorithm>
#include <array>
#include <bitset>
#include <fmt/core.h>
#include <memory>
#include <vector>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID get_component_id() {
  static ComponentID last_id = 0;
  return last_id++;
}

template <typename T> inline ComponentID get_component_id() noexcept {
  static ComponentID type_id = get_component_id();
  return type_id();
}

constexpr std::size_t max_components = 32;

using ComponentBitSet = std::bitset<max_components>;
using ComponentArray = std::array<Component *, max_components>;

class Component {
public:
  Entity *entity;
  virtual void init() {}
  virtual void update() {}
  virtual void draw() {}
  virtual ~Component() {}
};

class Entity {
public:
  bool active = true;
  std::vector<std::unique_ptr<Component>> components;
  ComponentArray component_array;
  ComponentBitSet component_bit_set;
};
