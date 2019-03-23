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

## Feature branches

May branch off from:

	develop

Must merge back into:

	develop

Branch naming convention

	feature-*,feature/*

Feature branches are uses to develop new features. Feature brach will exists as long as the feature is in development, but will eventually be merged back into develop(add for upcoming release) or discarded(in case of failure)

### Creating a feature branch

When starting work on a new feature, make sure the develop branch are updated
    
    $ git checkout Develop
    $ git fetch

Branch off from the develop branch

    $ git checkout Develop
    $ git checkout -b add-motion-control-algorithm
    $ git push -u origin add-motion-control-algorithm

When reach certain milestone for your development, commit to save your work locally and globally

    $ git add .
    $ git commit -m "message about your code changes"
    $ git push -u origin add-motion-control-algorithm

When your work is complete, tested and ready to be merged to Develop branch,do PR (Pull Request), the recommended way is doing this using Github GUI

* Go to the Github repository
* Select your branch
* Click "Compare & pull request" green button on the top right
* Double check your work
* Leave comment and attach files/images if any, to state your code work
* Check if there is any Merge Conflict and resolved them to continue the PR process

Finally, feature branch can be deleted. This also can be done inside Github GUI

## Release branches

May branch off from:

	develop

Must merge back into:

	develop and master

Branch naming convention:

	release-*

Release branches support preparation of a new production release. This branch allows for minor bug fixes. By doing this work on release branch, the develop branch is cleared to receive features for the next release.

When there is features that been developed at Develop branch and reach stable states, it's time to create release version for the features.

Use the following versioning format : vXXXX.YYYY.ZZZZ

* XXXX - Major
* YYYY - Minor
* ZZZZ - Build Number

Version number bumping

* **Major** - Indicate a major rewrite where backward compatibility cannot be assumed. This happens when a new major feature are ready to be release.
* **Minor** - If the name and major version number are identical, but the minor version<br>number is different, this indicates significant enhancement with the intention of backward compatiblity
* **Build Number** - A difference in build number represents a recompilation of the same source.<br>Different build numbers might be used when the processor, platform, or compiler changes. This happens for hot-fixes or bug-fixes

### Creating a release branch

    $ git checkout Develop
    $ git fetch
    $ git checkout -b release-v1.0.1

After creating a new branch and switching to it, we bump the version number. Some file change are needed so that all working copy will reflect the new version. Then the bump version is commited

	$ git commit -a -m "Bumped version number to v1.0.1"
    $ git push -u origin release-v1.0.1

This new branch may exist for a while. During this time, bug fixes may be applied in this branch. Adding large new features here is strictly prohibited.

### Finishing a release branch

Create PR for the release branch to be merged to master branch, the recommended way is doing this using Github GUI
    * Go to the Github repository
    * Select the new release branch
    * Click "Compare & pull request" green button on the top right
    * Leave comment and attach files/images if any, to state the new features

Finally, the changes made on the release branch need to be merged back into develop, so that future releses also contain these bug fixes.

	```
	$ git checkout develop
	$ git merge --no-ff release-v1.0.1
	```

Release branch must not be delete. So that user has the option to download old release if new release got problems.

## Hotfix Branches

May branch off from:

	master

Must merge back into:

	develop and master

Branch naming convention:

	hotfix-*, hotfix/*

Hotfix branches arise from the necessity to act immediately upon an undesired state of a live production version. When a critical bug in a production version must be resolved immediately, a hotfix branch may be branched off from the master branch. The essence is that work of team members in develop branch can continue, while another persion is preparing a quck production fix.

### Creating the hotfix branch

Hotfix branches are created from the master branch. For example, say verion v1.0.1 is the current production release running live and causing trouble due to a severe bug. We may then branch off a hotfix branch and start fixing the problem.

	$ git checkout master
	$ git checkout -b hotfix-v1.0.2

Minor version bumping are needed for hotfix. Replace the version number in respective files. Then commit the version bumping.

	$ git commit -a -m "Bumped version number to v1.0.2"

Then, fix the bug and commit the fix in seperate commits

	$ git commit -m "Fixed production problem"

### Finishing a hotfix branch

When finished, the hotfix needs to be merged back into master, but also needs to be merged back into develop, in order to ensure that the hotfix are included in the next release as well.

do PR (Pull Request), the recommended way is doing this using Github GUI

* Go to the Github repository
* Select your branch
* Click "Compare & pull request" green button on the top right
* Double check your work
* Leave comment and attach files/images if any, to state your code work
* Check if there is any Merge Conflict and resolved them to continue the PR process

Finally, include the hotfix in develop

	$ git checkout develop
	$ git merge --no-ff hotfix-v1.0.2

## Bug fixes inside Release branch

Since release branch need to always be merge into develop, every bug fixes can be done directly in release branch.


