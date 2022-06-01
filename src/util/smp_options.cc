/*
 * This file is open source software, licensed to you under the terms
 * of the Apache License, Version 2.0 (the "License").  See the NOTICE file
 * distributed with this work for additional information regarding copyright
 * ownership.  You may not use this file except in compliance with the License.
 *
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
/*
 * Copyright 2022 ScyllaDB
 */

#include <boost/program_options/options_description.hpp>
#include <seastar/core/resource.hh>
#include <seastar/core/smp_options.hh>

#include "core/program_options.hh"

namespace seastar {

namespace bpo = boost::program_options;

bpo::options_description get_smp_options_description() {
    program_options::options_description_building_visitor descriptor;
    smp_options(nullptr).describe(descriptor);
    return std::move(descriptor).get_options_description();
}

}
