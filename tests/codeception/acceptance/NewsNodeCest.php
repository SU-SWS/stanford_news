<?php

/**
 * Class NewsNodeCest
 */
class NewsNodeCest {

  /**
   * News node creation and editing.
   */
  public function testNewsNode(\AcceptanceTester $I) {
    $I->logInWithRole('administrator');
    $node = $I->createEntity([
      'type' => 'stanford_news',
      'title' => 'News Story',
      'su_news_headline' => 'This is a headline',
      'su_news_dek' => 'This is a dek',
      'su_news_byline' => 'This is a byline',
      'su_news_source' => ['uri' => 'https://test.com', 'title' => 'link text'],
      'su_news_featured_media_caption' => 'Featured media caption',
    ]);
    $I->amOnPage($node->toUrl()->toString());
    $I->canSee('News Story', 'h1');
  }

}
