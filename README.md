dedup is an in-progress command-line tool to deduplicate files and directories.

It is motivated by the author's need to organize duplicate files and directories
spread across a very large Google Drive folder, containing backups of various
old machines. For that reason, the project will first only support the output
format of `rsync ls`, though the APIs will cleanly support new formats in the
future.
