/*
 * Copyright (c) 2008-2021, Hazelcast, Inc. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <hazelcast/client/hazelcast_client.h>

int main() {
    auto hz = hazelcast::new_client().get();

    auto list = hz.get_list("list").get();

    list->add("Tokyo").then(boost::launch::deferred, [=] (boost::future<bool> f) {
       if (f.get()) {
           std::cout << "First addition is successfull!!!" << '\n';
           list->add("Paris").get();
           list->add("London").get();
           list->add("New York").get();
       }
    });

    std::cout << "Putting finished!" << std::endl;

    std::cout << "Finished" << std::endl;

    return 0;
}
