# 1. Enter the project directory
cd arrow-master

# 2. Initialize git
git init

# 3. Add all files (Web app, C++ engine, assets, docs)
git add .

# 4. Create your initial commit
git commit -m "Initial commit: Complete Arrow Master (C++, Web, PWA)"

# 5. Set main branch
git branch -M main

# 6. Link to your GitHub repository (replace with your username and repo name)
git remote add origin https://github.com/<YOUR_GITHUB_USERNAME>/arrow-master.git

# 7. Push to GitHub
git push -u origin main