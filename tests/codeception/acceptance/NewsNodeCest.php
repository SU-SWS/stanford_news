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
    $node = $this->createNewsNode($I);
    $I->amOnPage($node->toUrl()->toString());
    $I->canSee('This is a headline', 'h1');

    $I->amOnPage('/news');
    $I->canSee('This is a headline', 'h2');
    $I->canSee(date('F d, Y'));

    $I->click('Foo');
    $I->canSee('This is a headline', 'h2');
    $I->canSee(date('F d, Y'));

    $I->logInWithRole('authenticated');
    $I->amOnPage('/news');

    $I->click('This is a headline');
    // We can't get the new domain from codeception, so we just check if the
    // destination was redirected.
    $I->canSeeCurrentUrlEquals('/');
  }

  /**
   * After a node is created, it should invalidate the views.
   */
  public function testViewInvalidation(AcceptanceTester $I) {
    $I->amOnPage('/news');
    $I->dontSee('This is a headline');

    $I->logInWithRole('administrator');
    $I->amOnPage('/node/add/stanford_news');
    $I->fillField('Headline', 'This is a headline');
    $I->click('Save');
    $I->amOnPage('/user/logout');

    $I->amOnPage('/news');
    $I->canSee('This is a headline', 'h2');

    $I->logInWithRole('administrator');
    $I->amOnPage('/node/add/stanford_news');
    $I->fillField('Headline', 'Cache Buster');
    $I->click('Save');
    $I->amOnPage('/user/logout');

    $I->amOnPage('/news');
    $I->canSee('Cache Buster', 'h2');
  }

  protected function createNewsNode(AcceptanceTester $I, $node_title = NULL) {
    $term = $I->createEntity([
      'name' => 'Foo',
      'vid' => 'stanford_news_topics',
    ], 'taxonomy_term');

    return $I->createEntity([
      'type' => 'stanford_news',
      'title' => 'News Story',
      'su_news_headline' => $node_title ?: 'This is a headline',
      'su_news_dek' => 'This is a dek',
      'su_news_byline' => 'This is a byline',
      'su_news_source' => [
        'uri' => 'http://google.com',
        'title' => 'link text',
      ],
      'su_news_featured_media_caption' => 'Featured media caption',
      'su_news_topics' => $term->id(),
      'su_news_publishing_date' => date('Y-m-d'),
    ]);
  }

}
