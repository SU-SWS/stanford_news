# [Stanford News Extras Importer](https://github.com/SU-SWS/stanford_news)
##### Version: 7.x-3.1

Stanford News Extras feature provides extra fields needed to support SoE needs.

Installation
---

Install this module like any other module. [See Drupal Documentation](https://drupal.org/documentation/install/modules-themes/modules-7)

Configuration
-------------
Current approach to installing all the things for importing news from SoE

1. Install and enable modules: 
   * stanford_feeds_helper (https://github.com/SU-SWS/stanford_feeds_helper.git)
   * stanford_soe_helper https://github.com/SU-SOE/stanford_soe_helper.git
1. Pull the changes for:
   * stanford_image_styles
   * stanford_image
   * stanford_news
2. Revert features:
   * stanford_news_extras,
   * stanford_news_extras_importer,
   * stanford_news
3. Disable & uninstall: stanford_news_views
4. Enable: stanford_news_extras_views
5. If necessary, create Banner and Banner Overlay regions (they don't seem to get exported/imported)
6. Remove title on news banner block and flush caches
7. Update homepage with the new news block
8. Add block at the bottom of each news item to link back to the news listing page


Troubleshooting
---

If you are experiencing issues with this module try reverting the feature first. If you are still experiencing issues try posting an issue on the GitHub issues page.

Contribution / Collaboration
---

You are welcome to contribute functionality, bug fixes, or documentation to this module. If you would like to suggest a fix or new functionality you may add a new issue to the GitHub issue queue or you may fork this repository and submit a pull request. For more help please see [GitHub's article on fork, branch, and pull requests](https://help.github.com/articles/using-pull-requests)
