/**
 * Copyright (c) 2022 Robert Bosch GmbH
 *
 * This program and the accompanying materials are made available under the
 * terms of the Apache License, Version 2.0 which is available at
 * https://www.apache.org/licenses/LICENSE-2.0.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "sdk/QueryBuilder.h"
#include "sdk/Utils.h"

#include <algorithm>
#include <utility>

namespace velocitas {

Query::Query(std::vector<std::reference_wrapper<const DataPoint>> dataPoints,
             std::string                                          queryString)
    : m_selectedDataPoints{std::move(dataPoints)}
    , m_queryString{std::move(queryString)} {}

QueryBuilder QueryBuilder::select(const DataPoint& dataPoint) {
    QueryBuilder builder;
    builder.m_queryContext.emplace_back("SELECT");
    builder.m_queryContext.push_back(dataPoint.getPath());
    builder.m_selectedDataPoints.push_back(std::cref(dataPoint));
    return builder;
}

QueryBuilder
QueryBuilder::select(const std::vector<std::reference_wrapper<const DataPoint>>& dataPoints) {
    QueryBuilder builder;
    builder.m_queryContext.emplace_back("SELECT");

    std::vector<std::string> paths;
    paths.reserve(dataPoints.size());
    std::transform(dataPoints.begin(), dataPoints.end(), std::back_inserter(paths),
                   [](const auto& dataPoint) { return dataPoint.get().getPath(); });

    builder.m_queryContext.emplace_back(StringUtils::join(paths, ", "));

    builder.m_selectedDataPoints = dataPoints;
    return builder;
}

Query QueryBuilder::build() const {
    return Query(m_selectedDataPoints, StringUtils::join(m_queryContext, " "));
}

} // namespace velocitas
