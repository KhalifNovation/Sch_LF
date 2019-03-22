# Branching Strategy

Use this strategy for developing features or bugfix in this project repository.


## Branching Overview

| Branch         | Protected | Base Branch | Description                                                                                                |
|----------------|-----------|-------------|------------------------------------------------------------------------------------------------------------|
| Develop        | NO        | master      | The latest state of development (unstable)                                                                 |
| release-vX.Y.Z | NO        | Develop     | A temporary release branch for versioning                                                                  |
| master         | YES       | N/A         | What is live in production (stable)<br> A PR (Pull Request) is required to merge the code into master      |
| feature/your-feature-name        | NO        | Develop     | Features development work                                                                                  |
| hotfix/your-fix-name         | YES       | master      | Hotfix for live production (fast action)<br> A PR (Pull Request) is required to merge the code into master |
| bugfix/your-bug-name         | NO        | Develop     | Bugfix for Development code                                                                                |


## Use Cases

1. Make sure your Develop branch is up to date
    ```
    $ git checkout Develop
    $ git fetch
    ```

2. Create feature branch based off Develop branch
    ```
    $ git checkout Develop
    $ git checkout -b add-motion-control-algorithm
    $ git push -u origin add-motion-control-algorithm
    ```

3. Start your development work

4. When reach certain milestone for your development,
<br/>commit to save your work locally and globally
    ```
    $ git add .
    $ git commit -m "message about your code changes"
    $ git push -u origin add-motion-control-algorithm
    ```

5. When your work is complete, tested and ready to be merged to Develop branch,
<br/>do PR (Pull Request), the recommended way is doing this using Github GUI
    * Go to the Github repository
    * Select your branch
    * Click "Compare & pull request" green button on the top right
    * Double check your work
    * Leave comment and attach files/images if any, to state your code work
    * Check if there is any Merge Conflict and resolved them to continue the PR process


## Create and Deploy a release

1. When there is features that been developed at Develop branch and reach stable states,
<br>it's time to create release version for the features

2. Use versioning format as following vXXXX.YYYY.ZZZZ
    * XXXX - Major
    * YYYY - Minor
    * ZZZZ - Build Number

3. Here is the explanation on how each component work
    * **Major** - Indicate a major rewrite where backward compatibility cannot be assumed
    * **Minor** - If the name and major version number are identical, but the minor version<br>number is different, this indicates significant enhancement with the intention of backward compatiblity
    * **Build Number** - A difference in build number represents a recompilation of the same source.<br>Different build numbers might be used when the processor, platform, or compiler changes

4. Create release branch based off Develop branch
    ```
    $ git checkout Develop
    $ git fetch
    $ git checkout -b release-v1.0.1
    $ git push -u origin release-v1.0.1
    ```

5. Create PR for the release branch to be merged to master branch, the recommended way is doing this using Github GUI
    * Go to the Github repository
    * Select the new release branch
    * Click "Compare & pull request" green button on the top right
    * Leave comment and attach files/images if any, to state the new features
