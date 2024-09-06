#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <atomic>
#include <thread>


// Function to read lines from a list of files and update the total line count
void readLinesFromFiles(const std::vector<std::filesystem::directory_entry>& files, std::atomic<size_t>& totalLineCount) {
    size_t localLineCount = 0; // Local line count for the current thread
    for (const auto& file : files) {
        std::ifstream fileStream(file.path());
        std::string line;
        // Read lines from the file and count them
        while (std::getline(fileStream, line)) {
            ++localLineCount;  // Count lines in this file
        }
        // Update the global line count atomically
        totalLineCount += localLineCount;
    }
}


int main(int argc, char** argv) {
    std::cout << "Write a path to directory: ";
    std::string path;
    std::cin >> path; // Read the directory path from user input. You can simply write "text_files" as input. 

    std::filesystem::path dirPath(path);

    // Check if the provided path is a valid directory
    if (!std::filesystem::exists(dirPath) || !std::filesystem::is_directory(dirPath)) {
        std::cerr << "Invalid directory path.\n";
        return 1;
    }

    // Vector to hold all .txt files in the directory
    auto files = std::vector<std::filesystem::directory_entry>{};
    for (const auto& entry : std::filesystem::directory_iterator(dirPath)) {
        if (entry.path().extension() == ".txt") {
            files.push_back(entry); // Add .txt files to the vector
        }
    }

    // Atomic variable to store the total number of lines
    std::atomic<size_t> totalLineCount{0};

    // Determine the number of threads to use
    unsigned int numThreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;

    // Calculate the number of files each thread will process
    size_t filesPerThread = files.size() / numThreads;
    size_t remainder = files.size() % numThreads;

    size_t firstFileIdx = 0;
    for (unsigned int i = 0; i < numThreads; ++i) {
        size_t lastFileIdx = firstFileIdx + filesPerThread + (i < remainder ? 1 : 0); // Calculate the index range for the current thread
        std::vector<std::filesystem::directory_entry> filesInThread(files.begin() + firstFileIdx, files.begin() + lastFileIdx);
        // Create and start a thread to process filesInThread
        threads.emplace_back(readLinesFromFiles, std::move(filesInThread), std::ref(totalLineCount));
        firstFileIdx = lastFileIdx;
    }

    // Wait for all threads to finish
    for (auto& thread : threads) {
        thread.join();
    }
    
    // Output the total number of lines counted
    std::cout << "Total number of lines is: " << totalLineCount.load() << "\n";

    return 0;
}