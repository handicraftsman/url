// Copyright 2017 Glyn Matthews.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef NETWORK_URI_URI_SEARCH_PARAMETERS_INC
#define NETWORK_URI_URI_SEARCH_PARAMETERS_INC

#include <string>
#include <vector>
#include <network/optional.hpp>

namespace network {
class uri_search_parameters {
 public:
  using string_type = std::string;
  using value_type = std::pair<string_type, string_type>;
  using const_iterator = std::vector<value_type>::const_iterator;

  uri_search_parameters();

  explicit uri_search_parameters(const string_type &query);

  uri_search_parameters(std::initializer_list<value_type> parameters);

  void append(const string_type &name, const string_type &value);

  void remove(const string_type &name);

  optional<string_type> get(const string_type &name) const noexcept;

  bool contains(const string_type &name) const noexcept;

  void set(const string_type &name, const string_type &value);

  const_iterator begin() const noexcept;

  const_iterator end() const noexcept;

  string_type to_string() const;

  void sort();

 private:
  void update();

  std::vector<value_type> parameters_;
};
};

#endif  // NETWORK_URI_URI_SEARCH_PARAMETERS_INC