# C Containers

A collection of generic containers and data structures implemented in C, inspired by the C++ STL and other common data structure libraries.

The goal of this project is to explore generic programming in C, understand the underlying implementations of commonly used data structures, and build reusable components for future projects.

## Goals

- Implement reusable, type-agnostic containers in C.
- Explore different approaches to generic programming using `void *` and macros.
- Understand memory management, allocation strategies, and data structure trade-offs.
- Provide simple, consistent APIs suitable for use across different projects.
- Keep the library lightweight and easy to integrate into existing C projects.

## Planned Containers

- [ ] Queue - `queue`                                         
- [ ] Dynamic array - `vector`                       
- [ ] Hash table - `unordered_map` / `unordered_set` 
- [ ] Heap / priority queue `priority_queue`                        
- [ ] Doubly linked list - `list`                    
- [ ] Deque / circular buffer                        
- [ ] Balanced search tree - `map` / `set`           
- [ ] Stack - `stack`                                          
- [ ] Bitset  `bitset`                                       

Additional data structures and utilities may be added as the project evolves.

## Design Philosophy

- **Generic:** Support different element types through reusable implementations.
- **Lightweight:** Minimise dependencies and unnecessary abstractions.
- **Portable:** Aim for compatibility with standard C implementations.
- **Educational:** Prioritise understanding and experimentation alongside practical usability.
- **Reusable:** Design components to be easily integrated into other projects.

## Usage

The intended interface is a lightweight C library that can be integrated into projects with minimal setup. The exact API and integration approach will evolve as implementations are added.

## Status

This project is a work in progress, developed primarily for learning, experimentation, and personal use. APIs and implementations may change as the library develops.

## License

To be decided.
