
# Initialize Git if not already done
git init

# Add all files to staging area
git add .

# Commit your changes
git commit -m "Version 1.0.2 -- No Build or Test Directory. It is an optimized usage of the commit command which you can use to commit the directory to git repositories and also you can build the project by running the run.sh file in the Script directory. Also no Usage of cmake so just copy the cmake.txt file to use cmake."


# Check if the remote is set correctly
git remote -v


# Push your changes
git push -u origin master
