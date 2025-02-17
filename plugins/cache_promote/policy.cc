/*
  Licensed to the Apache Software Foundation (ASF) under one
  or more contributor license agreements.  See the NOTICE file
  distributed with this work for additional information
  regarding copyright ownership.  The ASF licenses this file
  to you under the Apache License, Version 2.0 (the
  "License"); you may not use this file except in compliance
  with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/
#include "swoc/BufferWriter.h"
#include "tscore/Random.h"
#include "policy.h"

bool
PromotionPolicy::doSample() const
{
  if (_sample > 0) {
    double r = ts::Random::drandom();

    if (_sample > r) {
      DBG("checking sampling, is %f > %f? Yes!", _sample, r);
    } else {
      DBG("checking sampling, is %f > %f? No!", _sample, r);
      return false;
    }
  }
  return true;
}

int
PromotionPolicy::create_stat(std::string_view name, std::string_view remap_identifier)
{
  int stat_id = -1;
  swoc::LocalBufferWriter<MAX_STAT_LENGTH> stat_name;

  stat_name.clear().restrict(1);
  stat_name.print("plugin.{}.{}.{}", PLUGIN_NAME, remap_identifier, name);
  stat_name.restore(1).write('\0');

  if (TS_ERROR == TSStatFindName(stat_name.data(), &stat_id)) {
    stat_id = TSStatCreate(stat_name.data(), TS_RECORDDATATYPE_INT, TS_STAT_NON_PERSISTENT, TS_STAT_SYNC_SUM);
    if (TS_ERROR == stat_id) {
      DBG("error creating stat_name: %s", stat_name.data());
    } else {
      DBG("created stat_name: %s, stat_id: %d", stat_name.data(), stat_id);
    }
  }

  return stat_id;
}
