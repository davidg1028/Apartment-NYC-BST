# Apartment-NYC-BST
Console-based C++ binary search tree for NYC apartment listings, with Visitor-pattern search and filtering.

Built as a data structures project.

## What it does

Apartment records are read from a CSV, inserted into a BST keyed on monthly rent, and then queried through a nested menu. Because the tree is ordered by rent, the cheapest and most expensive listings are just the leftmost and rightmost nodes — no traversal required. Queries that aren't rent-ordered (borough, square footage) are handled by visitor objects that ride along an in-order traversal and collect matches.

## Features

- Load apartment inventory from CSV at startup
- Search by borough (partial, case-insensitive match)
- Search by rent range
- Search by minimum square footage
- Report listings by specific borough or by square-footage bracket
- Find max/min rent (O(h) via tree structure) and max/min square footage (full traversal)
- Edit an existing apartment's rent or bedroom count in place
- Add a new apartment at runtime
- In-order, pre-order, and post-order traversals
