FileMind is an efficient, object-oriented Library Management Console Application built natively in C++. The project is engineered around core Standard Template Library (STL) data structures, demonstrating practical implementation strategies for data storage, dynamic tracking, order execution, and error resolution.

🛠️ Data Structures & Architecture
The backbone of FileMind relies heavily on choosing the right container for the right job:

std::vector (Books Inventory): Used to store the master inventory of books. Vectors provide contiguous memory access, making searching for books by unique IDs fast and deterministic.

std::list (Members Ledger & Issued Logs): Utilized for system registration and active user logs. A doubly linked list allows smooth insertions and deletions without requiring memory re-allocations when elements are removed.

std::stack (Recent Issues): Tracks modern transactional processing logs through Last-In, First-Out (LIFO) tracking. The most recently checked-out books appear at the top of the history feed.

std::queue (Recent Returns): Implements a First-In, First-Out (FIFO) queue layout mapping transaction receipts sequentially as books are checked back into storage.

✨ Key Features
Inventory Querying: Real-time visibility tracking across global text assets displaying unique tracking numbers, titles, and active statuses.

Robust Exception Gates: Embedded validation filters preventing operational violations—such as capping maximum concurrent allocations to 3 titles per subscriber card.

Dual-Layer Search Engines: Independent dynamic pointer mapping structures designed to look up books and records cleanly, reducing systemic invalid cross-references.

Sequential Auditing feeds: Immediate visibility into transient system registers showing chronological logs for both stacks and queues simultaneously.

📂 Project Directory Structure
FileMind

FileMind.cpp — Consolidated core codebase including application configurations and entry definitions.

README.md — Setup protocols, technical specifications, and runtime maps.

🚀 Compilation & Local Execution
System Requirements
Standard C++ Compile Utilities (GCC/G++ 11+ or Clang)

Terminal Support configuration (Linux, macOS Shell, or Windows Powershell)

Build Protocols
Open your terminal space inside the folder containing your project file.

Compile the executable utility using the following command:

Bash
g++ -std=c++11 FileMind.cpp -o FileMind
Run the compiled application framework locally:

Bash
./FileMind
🎮 Interface Map & Simulation
Upon loading up, the script prompts inputs using an operational numeric selection menu sequence:

Display Books: Scans and presents all catalog titles alongside their live structural visibility metrics.

Issue Book: Checks structural limitations, modifies availability status flags, and pushes values to the transactional stack.

Return Book: Drops index targets cleanly from the specific member tracker, queues execution variables, and updates inventory records.

View Transactions: Automatically flushes audit values to process stack/queue displays sequentially.

View Issued Books: Displays user check-out history sorted cleanly under independent query indices.

Exit: Breaks input loops securely without systemic memory leaks.
