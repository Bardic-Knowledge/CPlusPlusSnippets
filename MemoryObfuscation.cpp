#include <iostream>
#include <cstring>

class MemoryObfuscator {
public:
    // Constructor takes a key for XOR encryption
    MemoryObfuscator(unsigned char encryptionKey) : key(encryptionKey) {}

    // Obfuscate memory using XOR encryption
    void obfuscateMemory(char* data, size_t size) {
        for (size_t i = 0; i < size; ++i) {
            data[i] ^= key;
        }
    }

    // Deobfuscate memory using XOR encryption (for demonstration purposes)
    void deobfuscateMemory(char* data, size_t size) {
        obfuscateMemory(data, size);  // XOR encryption is its own inverse
    }

private:
    unsigned char key;
};

int main() {
    // Example usage of MemoryObfuscator
    char sensitiveData[] = "Hello, World!";
    size_t dataSize = std::strlen(sensitiveData);

    // Create MemoryObfuscator with a specific key
    MemoryObfuscator obfuscator(0xAB);

    // Obfuscate and print the obfuscated data
    obfuscator.obfuscateMemory(sensitiveData, dataSize);
    std::cout << "Obfuscated Data: " << sensitiveData << std::endl;

    // Deobfuscate and print the original data
    obfuscator.deobfuscateMemory(sensitiveData, dataSize);
    std::cout << "Deobfuscated Data: " << sensitiveData << std::endl;

    return 0;
}
