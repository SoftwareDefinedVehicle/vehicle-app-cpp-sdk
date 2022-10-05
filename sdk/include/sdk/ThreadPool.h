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

#ifndef VEHICLE_APP_SDK_THREADPOOL_H
#define VEHICLE_APP_SDK_THREADPOOL_H

#include "sdk/Job.h"

#include <condition_variable>
#include <functional>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

namespace velocitas {

/**
 * @brief Manages a pool of threads which are capable of executing jobs asynchronously.
 *
 */
class ThreadPool final {
public:
    using Job_t = std::function<void()>;

    ThreadPool();

    ~ThreadPool();

    /**
     * @brief Get the Instance object.
     *
     * @return std::shared_ptr<ThreadPool>
     */
    static std::shared_ptr<ThreadPool> getInstance();

    /**
     * @brief Execute the given job asynchronously in one of the worker threads.
     *
     * @param job  The job to execute.
     */
    void execute(JobPtr_t job);

    ThreadPool(const ThreadPool&)            = delete;
    ThreadPool(ThreadPool&&)                 = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;
    ThreadPool& operator=(ThreadPool&&)      = delete;

private:
    void threadLoop();

    std::mutex                                m_queueMutex;
    std::condition_variable                   m_cv;
    std::queue<JobPtr_t>                      m_jobs;
    std::vector<std::unique_ptr<std::thread>> m_workerThreads;
    bool                                      m_isRunning{true};
};

} // namespace velocitas

#endif // VEHICLE_APP_SDK_THREADPOOL_H