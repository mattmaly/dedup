dedup is an in-progress command-line tool to deduplicate files and directories.

It is motivated by the author's need to organize duplicate files and directories
spread across a very large Google Drive folder, containing backups of various
old machines. For that reason, the project will first only support the output
format of `rsync ls`, though the APIs will cleanly support new formats in the
future.

## Design Overview

dedup follows three steps:

1. Parses lines of input into a tree of File objects (a File represents either a
regular file or a directory).
2. Traverse the tree to compute a hash identifier for each File, and generate
a map from identifier to the set of Files with that identifier. The hash
identifier is expected to represent the contents of the File (and in the case of
a directory, the identifiers of the Files contained therein).
3. Find the most senior File tree nodes that have at least one other File with a
matching identifier. Report these as duplicates.
